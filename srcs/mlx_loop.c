/**
 * @file mlx_loop.c
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-11
 * 
 */

#include "mlx_internal.h"

int	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(void *), void *param)
{
	((t_mlx *)mlx_ptr)->loop_funct = funct_ptr;
	((t_mlx *)mlx_ptr)->loop_funct_param = param;
	return (0);
}

/**
 * @brief run loop
 * 
 * @param mlx_ptr 
 * @return int 
 */
int	mlx_loop (void *mlx_ptr)
{
	SDL_Event	event;

	((t_mlx *)mlx_ptr)->quit_loop = 0;
	while (!((t_mlx *)mlx_ptr)->quit_loop)
	{
		if (((t_mlx *)mlx_ptr)->loop_funct)
			((t_mlx *)mlx_ptr)->loop_funct(
				((t_mlx *)mlx_ptr)->loop_funct_param);
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				mlx_raise_quit(&((t_mlx *)mlx_ptr)->win);
				((t_mlx *)mlx_ptr)->quit_loop = 1;
			}
			if (event.type == SDL_KEYDOWN)
				mlx_raise_keydown(&((t_mlx *)mlx_ptr)->win, &event.key.keysym);
			if (event.type == SDL_KEYUP)
				mlx_raise_keyup(&((t_mlx *)mlx_ptr)->win, &event.key.keysym);
			if (event.type == SDL_WINDOWEVENT)
				if (event.window.event == SDL_WINDOWEVENT_SHOWN)
					mlx_raise_expose(&((t_mlx *)mlx_ptr)->win);
			if (event.type == SDL_MOUSEBUTTONDOWN)
				mlx_raise_mousedown(&((t_mlx *)mlx_ptr)->win, &event.button);
			if (event.type == SDL_MOUSEBUTTONUP)
				mlx_raise_mouseup(&((t_mlx *)mlx_ptr)->win, &event.button);
		}
		if (!((t_mlx *)mlx_ptr)->quit_loop)
		{
			SDL_RenderPresent(((t_mlx *)mlx_ptr)->win.render);
			SDL_Delay(100);
		}
	}
	mlx_destroy_window(mlx_ptr, ((t_mlx *)mlx_ptr)->win.render);
	return (0);
}
