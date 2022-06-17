/**
 * @file mlx_hook.c
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-17
 * 
 */

#include "mlx.h"
#include "mlx_internal.h"

SDL_Color	color_create(int color)
{
	SDL_Color	c;

	c.b = (color & 0xFF) / 255.0;
	c.g = ((color >> 8) & 0xFF) / 255.0;
	c.r = ((color >> 16) & 0xFF) / 255.0;
	c.a = 255;
	return (c);
}
