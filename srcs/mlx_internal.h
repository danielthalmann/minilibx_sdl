/**
 * @file mlx_internal.h
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-11
 * 
 */

#ifndef MLX_INTERNAL_H
#define	MLX_INTERNAL_H

#include "mlx_key.h"
#include "mlx_event.h"
#include <stdlib.h>
#include <SDL2/SDL.h>

#define COLOR_BY_PIXEL	4


typedef struct s_mlx_window
{
	SDL_Window 			*window;
	SDL_Renderer		*render;
	int 				width;
	int 				height;
	t_event_list		hooks[MLX_MAX_EVENTS];
	struct s_mlx_window	*next;
}	t_mlx_window;

typedef struct s_mlx
{
	int 				is_init;
	int					length;
	int					quit_loop;
	int 				(*loop_funct)(void *);
	void 				*loop_funct_param;
	t_mlx_window		win;
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
int			mlx_raise_expose (t_mlx_window *win_ptr);
int			mlx_raise_keydown(t_mlx_window *win_ptr, SDL_Keysym *keysym);
int			mlx_raise_keyup(t_mlx_window *win_ptr, SDL_Keysym *keysym);

#endif