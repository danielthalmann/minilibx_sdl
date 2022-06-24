/**
 * @file mlx_image.c
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-14
 * 
 */

#include "mlx.h"
#include "mlx_internal.h"

void	*mlx_new_image(void *mlx_ptr, int width, int height)
{
	t_mlx_img	*img;

	if (!(img = malloc(sizeof(t_mlx_img))))
		return (NULL);
	img->data = NULL;
	img->texture = SDL_CreateTexture(((t_mlx *)mlx_ptr)->win.render,
                               SDL_PIXELFORMAT_RGBA8888,
                               SDL_TEXTUREACCESS_TARGET,
                               width,
                               height);
	if (!img->texture)
	{
		free(img);
		return (NULL);
	}
	img->render = ((t_mlx *)mlx_ptr)->win.render;
	img->bpp = COLOR_BY_PIXEL * 8;
	img->width = width;
	img->height = height;
	return (img);
}

char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
			   int *size_line, int *endian)
{
	// maybe use SDL_RenderReadPixels(renderer, rect, format, pixels, pitch); ???
	*bits_per_pixel = ((t_mlx_img *)img_ptr)->bpp;
	*size_line = ((t_mlx_img *)img_ptr)->width * COLOR_BY_PIXEL;
	*endian = 0; // little endian

	if (!(((t_mlx_img *)img_ptr)->data = 
			calloc(((t_mlx_img *)img_ptr)->width * ((t_mlx_img *)img_ptr)->height * COLOR_BY_PIXEL,
			sizeof(char))))
		return (NULL);

	return ((char *)((t_mlx_img *)img_ptr)->data);
}

unsigned int	mlx_get_color_value(void *mlx_ptr, int color)
{
	(void) mlx_ptr;
	(void) color;
	
	return (color);
}

int	mlx_destroy_image(void *mlx_ptr, void *img_ptr)
{
	(void) mlx_ptr;
	SDL_DestroyTexture(((t_mlx_img *)img_ptr)->texture);
	free(((t_mlx_img *)img_ptr)->data);
	free(img_ptr);
	return (0);
}

void	mlx_refresh_texture(t_mlx_img *img)
{
	if (!(img->data))
		return ;
		
	SDL_SetRenderTarget(img->render, img->texture);

	SDL_Rect rect = {0, 0, 1, 1};
	for (int i = 0; i < img->width * img->height; i += COLOR_BY_PIXEL)
	{
		rect.x = (i / COLOR_BY_PIXEL) % img->width;
		rect.y = (i / COLOR_BY_PIXEL) / img->width;
		SDL_SetRenderDrawColor(img->render, img->data[i], img->data[i + 1], img->data[i + 2], 255);
		SDL_RenderFillRect(img->render, &rect);
//		printf ("color %d, %d, %d\n", img->data[i], img->data[i + 1], img->data[i + 2]);
//		SDL_SetTextureColorMod(img->texture,
//			img->data[i], img->data[i + 1], img->data[i + 2]);
	}

	SDL_SetRenderTarget(img->render, NULL);
}