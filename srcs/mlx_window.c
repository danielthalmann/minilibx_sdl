/**
 * @file mlx_window.c
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-11
 * 
 */

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
	((t_mlx *)mlx_ptr)->win.window = SDL_CreateWindow(title,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size_x, size_y,
		SDL_WINDOW_SHOWN);
	((t_mlx *)mlx_ptr)->win.width = size_x;
	((t_mlx *)mlx_ptr)->win.height = size_y;

	((t_mlx *)mlx_ptr)->win.render = SDL_CreateRenderer(((t_mlx *)mlx_ptr)->win.window,
                                 -1, // first renderer mode
                                 SDL_RENDERER_ACCELERATED);
	return (&((t_mlx *)mlx_ptr)->win);
}

int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
				int x, int y)
{
	(void) win_ptr;
	(void) mlx_ptr;
	(void) x;
	(void) y;

	SDL_Rect	dst = {0, 0, 0, 0};

	dst.x = x;
	dst.y = y;
	dst.w = ((t_mlx_img *)img_ptr)->width;
	dst.h = ((t_mlx_img *)img_ptr)->height;
	// SDL_QueryTexture(((t_mlx_img *)img_ptr)->texture, NULL, NULL, &dst.w, &dst.h);

	mlx_refresh_texture(img_ptr);

	SDL_RenderCopy(((t_mlx_window *)win_ptr)->render,
                   ((t_mlx_img *)img_ptr)->texture,
                   NULL,
                   &dst);
	return (0);
}

int	mlx_clear_window(void *mlx_ptr, void *win_ptr)
{
	(void) mlx_ptr;

	if (SDL_SetRenderDrawColor(((t_mlx_window *)win_ptr)->render,
			0, 0, 0, 255) != 0)
		return (-1);
	if (SDL_RenderClear(((t_mlx_window *)win_ptr)->render) != 0)
		return (-1);
	return (0);  
}

int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color)
{
	SDL_Color	c;
	SDL_Point	p;

	(void) mlx_ptr;
	p.x = x;
	p.y = y;
	c = mlx_color_create(color);
	if (SDL_SetRenderDrawColor(((t_mlx_window *)win_ptr)->render,
			c.r, c.g, c.b, c.a) != 0)
		return (-1);
	SDL_RenderDrawPoints(((t_mlx_window *)win_ptr)->render, &p, 1);
	return (0);
}

int	mlx_destroy_window(void *mlx_ptr, void *win_ptr)
{
	(void) mlx_ptr;
	(void) win_ptr;

	((t_mlx *)mlx_ptr)->quit_loop = 1;
	if (((t_mlx_window *)win_ptr)->render)
	{
		SDL_DestroyRenderer(((t_mlx_window *)win_ptr)->render);
		((t_mlx_window *)win_ptr)->render = 0;
	}
	if (((t_mlx_window *)win_ptr)->window)
	{
		SDL_DestroyWindow(((t_mlx_window *)win_ptr)->window);
		((t_mlx_window *)win_ptr)->window = 0;
	}
	SDL_Quit();
	return (0);
}