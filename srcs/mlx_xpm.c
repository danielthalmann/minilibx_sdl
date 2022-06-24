/**
 * @file mlx_xpm.c
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-24
 *
 */

#include "mlx_internal.h"
#include <stdio.h>
#include <string.h>

int	xpm_set_header(t_xpm *xpm, char *header)
{
	int size;

	size = sscanf(header, "%d %d %d %d"
		, &xpm->header.width
		, &xpm->header.height
		, &xpm->header.color_palette
		, &xpm->header.chars_per_pixel);
	
	if (size != 4)
		return (1);
	
	xpm->colors = malloc(sizeof(t_xpm_color) * xpm->header.color_palette);

	if(!xpm->colors)
		return (1);

	xpm->image = malloc(sizeof(int) * xpm->header.width * xpm->header.height);

	memset(xpm->image, 0, sizeof(int) * xpm->header.width * xpm->header.height);

	if(!xpm->image)
		return (1);

	return (0);
}

int	ft_valid_base(int b, char *base)
{
	int	i;
	int	j;

	if (b < 2)
		return (0);
	i = 0;
	while (i < b - 1)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (j < b)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (base[++i] == '+' || base[i] == '-')
		return (0);
	return (1);
}

unsigned int	ft_get_value(char *str, char *base, int b)
{
	unsigned int	value;
	int				i;

	value = 0;
	while (*str)
	{
		i = 0;
		while (base[i] != *str && i < b)
			i++;
		if (i == b)
			return (0);
		value *= b;
		value += i;
		str++;
	}
	return (value);
}

int	atoi_base(char *str, char *base)
{
	int	b;
	int	neg;

	b = strlen(base);
	if (!ft_valid_base(b, base))
		return (0);
	while (*str && isspace(*str))
		str++;
	neg = 1;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	return (neg * ft_get_value(str, base, b));
}


unsigned int	str_to_color(char *s)
{
	if (*s == '#')
		return (atoi_base(++s, "0123456789ABCDEF"));
	
	if (strcmp(s, "white") == 0)
		return (0xFFFFFFFF);
	
	return (0);
}

void	xpm_set_colors(t_xpm *xpm, int idx, char *color)
{
	xpm->colors[idx].chars_pixel = malloc(sizeof(char) * (xpm->header.chars_per_pixel + 1));
	strncpy(xpm->colors[idx].chars_pixel, color, xpm->header.chars_per_pixel);
	xpm->colors[idx].chars_pixel[xpm->header.chars_per_pixel] = '\0';
	xpm->colors[idx].color = str_to_color(&color[3 + xpm->header.chars_per_pixel]);
}

int		xpm_get_color_of(t_xpm *xpm, char *s)
{
	for (int i = 0; i < xpm->header.color_palette; i++)
	{
		if (strncmp(s, xpm->colors[i].chars_pixel, xpm->header.chars_per_pixel) == 0)
			return (xpm->colors[i].color);
	}
	return (0);
}

void	xpm_set_image(t_xpm *xpm, int y, char *row)
{
	for (int x = 0; x < xpm->header.width; x++)
		xpm->image[(y * xpm->header.width) + x] = 
			xpm_get_color_of(xpm, &row[x * xpm->header.chars_per_pixel]);
}

void	xpm_print_info(t_xpm *xpm)
{
	printf("xpm info :\n");
	printf("\twidth : %d\n", xpm->header.width);
	printf("\theight : %d\n", xpm->header.height);
	printf("\tpalette size : %d\n", xpm->header.color_palette);
	printf("\tchar per pixel : %d\n", xpm->header.chars_per_pixel);

	for (int y = 0; y < xpm->header.color_palette; y++)
		printf("\tcolor : %d char : [%s] \n", xpm->colors[y].color, xpm->colors[y].chars_pixel);
}

void	xpm_free(t_xpm *xpm)
{
	int	i;

	for (i = 0; i < xpm->header.color_palette; i++)
		free(xpm->colors[i].chars_pixel);
	free(xpm->colors);
	free(xpm->image);
}
