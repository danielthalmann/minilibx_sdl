/**
 * @file mlx_event.h
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-19
 * 
 */

#ifndef MLX_EVENT_H
# define MLX_EVENT_H

# define MLX_MAX_EVENTS 26

enum e_mlx_event {
	MLX_ON_KEY_PRESS = 2,
	MLX_ON_KEY_RELEASE = 3,
	MLX_ON_BUTTON_PRESS = 4,
	MLX_ON_BUTTON_RELEASE = 5,
	MLX_ON_MOTION_NOTIFY = 6,
	MLX_ON_EXPOSE = 12,
	MLX_ON_DESTROY = 17
};

typedef struct s_event_list
{
	int		mask;
	int		(*hook)();
	void	*param;
}				t_event_list;


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
