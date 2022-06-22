/**
 * @file mlx_event.c
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-22
 * 
 */

#include "mlx.h"
#include "mlx_internal.h"

int	mlx_raise_expose(t_mlx_window *win_ptr)
{
	win_ptr->hooks[MLX_ON_BUTTON_PRESS].mask = 0;
	if (win_ptr->hooks[MLX_ON_EXPOSE].hook)
	{
		win_ptr->hooks[MLX_ON_EXPOSE].hook(
			win_ptr->hooks[MLX_ON_BUTTON_PRESS].param);
	}
	return (0);
}

int	mlx_raise_keyup(t_mlx_window *win_ptr, SDL_Keysym *keysym)
{
	if (win_ptr->hooks[MLX_ON_KEY_RELEASE].hook != NULL)
	{
		win_ptr->hooks[MLX_ON_KEY_RELEASE].hook(
			mlx_keycode_to_mxl_key(keysym->scancode),
			win_ptr->hooks[MLX_ON_KEY_RELEASE].param);
	}
	return (0);
}

int	mlx_raise_keydown(t_mlx_window *win_ptr, SDL_Keysym *keysym)
{
	if (win_ptr->hooks[MLX_ON_KEY_PRESS].hook) 
	{
		win_ptr->hooks[MLX_ON_KEY_PRESS].hook(
			mlx_keycode_to_mxl_key(keysym->scancode),
			win_ptr->hooks[MLX_ON_KEY_PRESS].param);
	}
	return (0);
}

int	mlx_raise_quit(t_mlx_window *win_ptr)
{
	if (win_ptr->hooks[MLX_ON_DESTROY].hook) 
	{
		win_ptr->hooks[MLX_ON_DESTROY].hook(
			win_ptr->hooks[MLX_ON_DESTROY].param);
	}
	return (0);
}

int mlx_raise_mousedown(t_mlx_window *win_ptr, SDL_MouseButtonEvent *m)
{
	if (win_ptr->hooks[MLX_ON_BUTTON_PRESS].hook) 
	{
		// int (*f)(int button, int x, int y, void *param)

		win_ptr->hooks[MLX_ON_BUTTON_PRESS].hook(
			mlx_sdl_button_to_mlx_button(m->button),
			m->x,
			m->y,
			win_ptr->hooks[MLX_ON_BUTTON_PRESS].param);
	}
	return (0);
}

int mlx_raise_mouseup(t_mlx_window *win_ptr, SDL_MouseButtonEvent *m)
{
	if (win_ptr->hooks[MLX_ON_BUTTON_RELEASE].hook) 
	{
		// int (*f)(int button, int x, int y, void *param)

		win_ptr->hooks[MLX_ON_BUTTON_RELEASE].hook(
			mlx_sdl_button_to_mlx_button(m->button),
			m->x,
			m->y,
			win_ptr->hooks[MLX_ON_BUTTON_RELEASE].param);
	}
	return (0);
}