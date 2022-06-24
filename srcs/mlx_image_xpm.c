/**
 * @file mlx_image_xpm.c
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-14
 *
 */

#include "mlx_internal.h"

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <ctype.h>
# include <stdio.h>

void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
			  int *width, int *height)
{

	(void) mlx_ptr;
	(void) xpm_data;
	(void) width;
	(void) height;

	int			i;
	t_xpm		xpm;
	t_mlx_img	*img;

	if (!*xpm_data || !*xpm_data)
		return (NULL);

	if (xpm_set_header(&xpm, *xpm_data))
		return (NULL);

	i = 0;
	while (xpm_data[++i] && (i - 1) < xpm.header.color_palette)
		xpm_set_colors(&xpm, (i - 1), xpm_data[i]);

	i--;
	while (xpm_data[++i])
		xpm_set_image(&xpm, (i - 1 - xpm.header.color_palette), xpm_data[i]);

	img = (t_mlx_img *)mlx_new_image(mlx_ptr, xpm.header.width, xpm.header.height);

	if(img)
	{
		SDL_SetTextureBlendMode(img->texture, SDL_BLENDMODE_BLEND);

		SDL_SetRenderTarget(img->render, img->texture);

		SDL_Rect rect = {0, 0, 1, 1};
		for (int i = 0; i < img->width * img->height; i++)
		{
			rect.x = (i) % img->width;
			rect.y = (i) / img->width;

			SDL_SetRenderDrawColor(img->render, ((xpm.image[i] >> 16) & 0xFF),
				((xpm.image[i] >> 8) & 0xFF),
				((xpm.image[i]) & 0xFF),
				((xpm.image[i] >> 24) & 0xFF));
			SDL_RenderFillRect(img->render, &rect);
		}

		SDL_SetRenderTarget(img->render, NULL);		
	}
	
	xpm_free(&xpm);

	return (img);
}

int	slen(char *s)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*join(char *s1, char *s2, int l2)
{
	int		len1;
	int		len2;
	int		i;
	char	*ret;

	len1 = slen(s1);
	len2 = slen(s2);
	if (l2 < len2)
		len2 = l2;
	ret = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!ret)
		return (0);
	i = -1;
	while (++i < len1)
		ret[i] = s1[i];
	i--;
	while (++i < len1 + len2)
		ret[i] = s2[i - len1];
	ret[i] = 0;
	free(s1);
	return (ret);
}

void	read_buffer(int fd, t_buffer_read *buf)
{
	if (buf->pos == buf->last_read)
	{
		buf->last_read = read(fd, buf->buffer, BUFFER_SIZE);
		buf->buffer[buf->last_read] = 0;
		buf->pos = 0;
		buf->pos_end = 0;
	}
}

char	*get_nextline(int fd)
{
	static t_buffer_read	buf;
	char					*ret;
	int						end;

	ret = 0;
	end = 0;
	read_buffer(fd, &buf);
	while (buf.last_read)
	{
		while (buf.pos_end < buf.last_read && buf.buffer[buf.pos_end] != '\n')
			buf.pos_end++;
		if (buf.buffer[buf.pos_end] == '\n')
		{
			buf.pos_end++;
			end = 1;
		}
		ret = join(ret, (buf.buffer + buf.pos), (buf.pos_end) - buf.pos);
		buf.pos = buf.pos_end;
		if (end)
			return (ret);
		read_buffer(fd, &buf);
	}
	return (ret);
}

int	has_start_comment(char *s)
{
	if (s && *s)
	{
		while(isspace(*s))
			s++;
		if (strncmp(s, "/*", 2) == 0)
			return (1);
	}
	return (0);
}

int	has_stop_comment(char *s)
{
	while (*s)
	{
		if (*s == '*')
			if (strncmp(s, "*/", 2) == 0)
				return (1);
		s++;
	}
	return (0);
}

void	read_next(int fd, char **line)
{
	if (*line)
		free(*line);

	*line = get_nextline(fd);

	if (*line && has_start_comment(*line))
	{
		while (!has_stop_comment(*line))
		{
			free(*line);
			*line = get_nextline(fd);
		}
		free(*line);
		*line = get_nextline(fd);
	}
}

int	slen_to(char *s, char c)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

void	*close_fd_return_null(int fd)
{
	close(fd);
	return (NULL);
}

void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
				int *width, int *height)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	**xpm_data;
	t_list	*list;
	int		list_length;
	int		i;
	void	*ret;

	list_length = 0;
	list = NULL;
	fd = open(filename, O_RDONLY);
	if (fd)
	{
		/* first line must be XPM */
		line = get_nextline(fd);
		if (!line)
			return (close_fd_return_null(fd));
		if (strncmp(line, XPM_FILE_HEADER, 9) != 0)
			return (close_fd_return_null(fd));

		/* the second instruction must contain "static char *" */
		read_next(fd, &line);
		if (!line)
			return (close_fd_return_null(fd));
		if (strncmp(line, "static char *", 13) != 0)
		{
			close(fd);
			return (NULL);
		}
		read_next(fd, &line);
		while (line && *line)
		{
			if (*line == '"')
			{
				i = slen_to(&line[1], '"');
				tmp = malloc((i + 1) * sizeof(char));
				strncpy(tmp, &line[1], i);
				tmp[i] = '\0';
				lst_add_back(&list, lst_new(tmp));
				list_length++;
			}
			read_next(fd, &line);
		}
		free(line);
	}
	close(fd);
	xpm_data = cpy_list_to_char(list, list_length);
	lst_clear(&list, NULL);

	ret = (mlx_xpm_to_image(mlx_ptr, xpm_data,
			  width, height));

	// free list xpm_data
	i = -1;
	while (xpm_data[++i])
		free (xpm_data[i]);
	free (xpm_data);

	return (ret);
}
