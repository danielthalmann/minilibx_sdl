/**
 * @file mlx_mouse.c
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-14
 * 
 */

#include "mlx.h"
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
