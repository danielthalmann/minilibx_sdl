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
	(void) mlx_ptr;
	(void) width;
	(void) height;

	return (NULL);
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
	(void) img_ptr;
	
	return (0);
}