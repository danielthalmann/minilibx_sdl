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
	if (!(img->data = malloc(width * height * 4)))
	{
		free(img);
		return (NULL);
	}
	img->texture = SDL_CreateTexture(((t_mlx *)mlx_ptr)->render,
                               SDL_PIXELFORMAT_RGBA8888,
                               SDL_TEXTUREACCESS_STREAMING,
                               width,
                               height);
	if (!img->texture)
	{
		free(img->data);
		free(img);
		return (NULL);
	}
	img->bpp = 32;
	img->width = width;
	img->height = height;
	return (img);
}

/*
**  return void *0 if failed
*/
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
			   int *size_line, int *endian)
{
	(void) img_ptr;
	(void) bits_per_pixel;
	(void) size_line;
	(void) endian;

	return (NULL);
}

unsigned int	mlx_get_color_value(void *mlx_ptr, int color)
{
	(void) mlx_ptr;
	(void) color;
	
	return (0);
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
	for (int i = 0; i < img->width * img->height; i += 4)
	{
		SDL_SetTextureColorMod(img->texture,
			img->data[i], img->data[i + 1], img->data[i + 2]);
	}
}