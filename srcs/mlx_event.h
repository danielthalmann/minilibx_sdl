/**
 * @file mlx_event.h
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-19
 * 
 */

#ifndef MLX_EVENT_H
# define MLX_EVENT_H

enum {
	MLX_ON_KEYDOWN = 2,
	MLX_ON_KEYUP = 3,
	MLX_ON_MOUSEDOWN = 4,
	MLX_ON_MOUSEUP = 5,
	MLX_ON_MOUSEMOVE = 6,
	MLX_ON_EXPOSE = 12,
	MLX_ON_DESTROY = 17
};

// Event		Prototype
//------------------------------------------------------------
// KEYDOWN	 	int (*f)(int keycode, void *param)
// KEYUP 	 	int (*f)(int keycode, void *param)
// MOUSEDOWN  	int (*f)(int button, int x, int y, void *param)
// MOUSEUP	 	int (*f)(int button, int x, int y, void *param)
// MOUSEMOVE 	int (*f)(int x, int y, void *param)
// EXPOSE 	 	int (*f)(void *param)
// DESTROY	 	int (*f)(void *param)

#endif
