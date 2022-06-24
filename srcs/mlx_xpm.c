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

	return (0);
}

int	str_to_color(char *s)
{
	if (*s == '#')
		return (atoi(++s));
	if (strcmp(s, "white"))
		return (0xFFFFFF);
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

void	xpm_free(t_xpm *xpm)
{
	int	i;

	for (i = 0; i < xpm->header.color_palette; i++)
		free(xpm->colors[i].chars_pixel);
	free(xpm->colors);
	free(xpm->image);
}
