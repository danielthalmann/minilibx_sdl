/**
 * @file mlx_hook.c
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-14
 * 
 */

#include "mlx.h"
#include "mlx_internal.h"

int	mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param)
{
	(void) win_ptr;
	(void) funct_ptr;
	(void) param;

	return (0);
}

int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param)
{
	(void) win_ptr;
	(void) funct_ptr;
	(void) param;

	return (0);
}

int	mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param)
{
	(void) win_ptr;
	(void) funct_ptr;
	(void) param;

	return (0);
}

int	mlx_hook(void *win_ptr, int x_event, int x_mask,
                 int (*funct)(), void *param)
{
	(void) win_ptr;
	(void) x_event;
	(void) x_mask;
	(void) funct;
	(void) param;

	return (0);
}
