/**
 * @file mlx_image_xpm.c
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-14
 * 
 */

#include "mlx.h"
#include "mlx_internal.h"

void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
			  int *width, int *height)
{
	(void) mlx_ptr;
	(void) xpm_data;
	(void) width;
	(void) height;

	return (NULL);
}

void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
			       int *width, int *height)
{
	(void) mlx_ptr;
	(void) filename;
	(void) width;
	(void) height;

	return (NULL);
}
