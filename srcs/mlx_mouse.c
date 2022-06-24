/**
 * @file mlx_mouse.c
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-14
 * 
 */

#include "mlx_internal.h"

int     mlx_mouse_hide()
{
	SDL_ShowCursor(SDL_DISABLE);
	return (0);
}

int     mlx_mouse_show()
{
	SDL_ShowCursor(SDL_ENABLE);
	return (0);
}

int     mlx_mouse_move(void *win_ptr, int x, int y)
{
	(void) win_ptr;
	(void) x;
	(void) y;

	return (0);
}

int     mlx_mouse_get_pos(void *win_ptr, int *x, int *y)
{
	(void) win_ptr;
	(void) x;
	(void) y;

	return (0);
}

int		mlx_sdl_button_to_mlx_button(int button)
{
	switch (button)
	{
	case SDL_BUTTON_LEFT:
		return (1);
	case SDL_BUTTON_MIDDLE:
		return (3);
	case SDL_BUTTON_RIGHT:
		return (2);
	case SDL_BUTTON_X1:
		return (4);
	case SDL_BUTTON_X2:
		return (5);
	default:
		return (1);
	}
}
