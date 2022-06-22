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
	((t_mlx_window *)win_ptr)->hooks[MLX_ON_BUTTON_PRESS].mask = 0;
	((t_mlx_window *)win_ptr)->hooks[MLX_ON_BUTTON_PRESS].hook = funct_ptr;
	((t_mlx_window *)win_ptr)->hooks[MLX_ON_BUTTON_PRESS].param = param;

	return (0);
}

int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param)
{
	((t_mlx_window *)win_ptr)->hooks[MLX_ON_KEY_RELEASE].mask = 0;
	((t_mlx_window *)win_ptr)->hooks[MLX_ON_KEY_RELEASE].hook = funct_ptr;
	((t_mlx_window *)win_ptr)->hooks[MLX_ON_KEY_RELEASE].param = param;

	return (0);
}

int	mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param)
{
	((t_mlx_window *)win_ptr)->hooks[MLX_ON_EXPOSE].mask = 0;
	((t_mlx_window *)win_ptr)->hooks[MLX_ON_EXPOSE].hook = funct_ptr;
	((t_mlx_window *)win_ptr)->hooks[MLX_ON_EXPOSE].param = param;

	return (0);
}

int	mlx_hook(void *win_ptr, int x_event, int x_mask,
                 int (*funct)(), void *param)
{
	((t_mlx_window *)win_ptr)->hooks[x_event].mask = x_mask;
	((t_mlx_window *)win_ptr)->hooks[x_event].hook = funct;
	((t_mlx_window *)win_ptr)->hooks[x_event].param = param;

	return (0);
}
