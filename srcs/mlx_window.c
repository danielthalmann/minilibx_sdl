/**
 * @file mlx.c
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

//int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
//				int x, int y);