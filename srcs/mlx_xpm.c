/**
 * @file mlx_xpm.c
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-24
 *
 */

#include "mlx_internal.h"

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
