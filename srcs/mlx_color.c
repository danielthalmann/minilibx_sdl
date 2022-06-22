/**
 * @file mlx_color.c
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-17
 * 
 */

#include "mlx.h"
#include "mlx_internal.h"

SDL_Color	mlx_color_create(int color)
{
	SDL_Color	c;

	c.b = (color & 0xFF);
	c.g = ((color >> 8) & 0xFF);
	c.r = ((color >> 16) & 0xFF);
	c.a = SDL_ALPHA_OPAQUE;
	return (c);
}
