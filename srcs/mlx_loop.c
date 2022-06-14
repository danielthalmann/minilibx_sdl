/**
 * @file mlx_loop.c
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-11
 * 
 */

#include "mlx.h"
#include "mlx_internal.h"


int	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(void *), void *param)
{
	((t_mlx *)mlx_ptr)->loop_funct = funct_ptr;
	((t_mlx *)mlx_ptr)->loop_funct_param = param;
	return (1);
}

/**
 * @brief run loop
 * 
 * @param mlx_ptr 
 * @return int 
 */
int	mlx_loop (void *mlx_ptr)
{
	int			quit;
	SDL_Event	event;

	quit = 0;
	while (!quit)
	{
		if (((t_mlx *)mlx_ptr)->loop_funct)
			((t_mlx *)mlx_ptr)->loop_funct(
				((t_mlx *)mlx_ptr)->loop_funct_param);
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				quit = 1;			
		}
		SDL_Delay(100);
	}
	SDL_DestroyWindow(((t_mlx *)mlx_ptr)->window);
	SDL_Quit();
	return (1);
}

