/**
 * @file mlx_internal.h
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-11
 * 
 */

#ifndef MLX_INTERNAL_H
#define	MLX_INTERNAL_H

#include <SDL2/SDL.h>

typedef struct s_mlx
{
	SDL_Window *window;
	int is_init;
	int width;
	int height;
	int (*loop_funct)(void *);
	void *loop_funct_param;
}	t_mlx;

#endif