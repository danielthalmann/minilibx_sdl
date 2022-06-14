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
	return (((t_mlx *)mlx_ptr)->window);
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

	return (0);
}

int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color)
{
	(void) mlx_ptr;
	(void) win_ptr;
	(void) x;
	(void) y;
	(void) color;

	return (0);
}

int	mlx_destroy_window(void *mlx_ptr, void *win_ptr)
{
	(void) mlx_ptr;
	(void) win_ptr;

	return (0);
}