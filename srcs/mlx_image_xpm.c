/**
 * @file mlx_image_xpm.c
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-14
 * 
 */

#include "mlx.h"
#include "mlx_internal.h"

# include <unistd.h>
# define BUFFER_SIZE 512

void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
			  int *width, int *height)
{

	(void) mlx_ptr;
	(void) xpm_data;
	(void) width;
	(void) height;

	return (NULL);
}

void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
			       int *width, int *height)
{
	(void) mlx_ptr;
	(void) filename;
	(void) width;
	(void) height;

	return (NULL);
}

typedef struct s_buffer_read
{
	int		fd;
	int		pos;
	int		pos_end;
	int		size;
	int		last_read;
	char	buffer[BUFFER_SIZE + 1];
}	t_buffer_read;

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
