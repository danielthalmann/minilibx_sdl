/**
 * @file mlx_internal.h
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-11
 * 
 */

#ifndef MLX_INTERNAL_H
#define	MLX_INTERNAL_H

#include "mlx_key.h"
#include <SDL2/SDL.h>

typedef struct s_mlx
{
	SDL_Window 		*window;
	SDL_Renderer	*render;
	int 			is_init;
	int 			width;
	int 			height;
	int				quit_loop;
	int 			(*loop_funct)(void *);
	void 			*loop_funct_param;
}	t_mlx;

SDL_Color	color_create(int color);

#endif