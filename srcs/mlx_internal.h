/**
 * @file mlx_internal.h
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-11
 * 
 */

#ifndef MLX_INTERNAL_H
#define	MLX_INTERNAL_H

#include "mlx_key.h"
#include <stdlib.h>
#include <SDL2/SDL.h>

#define COLOR_BY_PIXEL	4

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

typedef struct s_mlx_img
{
	SDL_Texture		*texture;
	SDL_Renderer	*render;
	int				bpp;
	int				width;
	int				height;
	unsigned char	*data;
}	t_mlx_img;

SDL_Color	mlx_color_create(int color);
void		mlx_refresh_texture(t_mlx_img *img);

#endif