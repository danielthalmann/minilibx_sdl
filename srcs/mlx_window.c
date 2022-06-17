/**
 * @file mlx_window.c
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-11
 * 
 */

#include "mlx.h"
#include "mlx_internal.h"

/**
 * @brief create a new window
 * 
 * @param mlx_ptr 
 * @param size_x 
 * @param size_y 
 * @param title 
 * @return void* 
 */
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
{
	((t_mlx *)mlx_ptr)->window = SDL_CreateWindow(title,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size_x, size_y,
		SDL_WINDOW_SHOWN);
	((t_mlx *)mlx_ptr)->width = size_x;
	((t_mlx *)mlx_ptr)->height = size_y;

	((t_mlx *)mlx_ptr)->render = SDL_CreateRenderer(((t_mlx *)mlx_ptr)->window,
                                 -1, // first renderer mode
                                 SDL_RENDERER_ACCELERATED);
	return (((t_mlx *)mlx_ptr)->render);
}

int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
				int x, int y)
{
	(void) mlx_ptr;
	(void) win_ptr;
	(void) img_ptr;
	(void) x;
	(void) y;

	return (0);
}

int	mlx_clear_window(void *mlx_ptr, void *win_ptr)
{
	(void) mlx_ptr;
	(void) win_ptr;

	if(SDL_SetRenderDrawColor(((t_mlx *)mlx_ptr)->render,
			100, 125, 200, 255) != 0)
		return (-1);
	if(SDL_RenderClear(((t_mlx *)mlx_ptr)->render) != 0)
		return (-1);
	return (0);  
}

int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color)
{
	SDL_Color	c;
	SDL_Point	p;

	p.x = x;
	p.y = y;
	c = color_create(color);
	if(SDL_SetRenderDrawColor(((t_mlx *)mlx_ptr)->render,
			c.r, c.g, c.b, c.a) != 0)
		return (-1);
	SDL_RenderDrawPoints(win_ptr, &p, 1);
	return (0);
}

int	mlx_destroy_window(void *mlx_ptr, void *win_ptr)
{
	(void) mlx_ptr;
	(void) win_ptr;

	if(((t_mlx *)mlx_ptr)->render)
	{
		SDL_DestroyRenderer(((t_mlx *)mlx_ptr)->render);
		((t_mlx *)mlx_ptr)->render = 0;
	}
	if(((t_mlx *)mlx_ptr)->window)
	{
		SDL_DestroyWindow(((t_mlx *)mlx_ptr)->window);
		((t_mlx *)mlx_ptr)->window = 0;
	}
	SDL_Quit();
	return (0);
}