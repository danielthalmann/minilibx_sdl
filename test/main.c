
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

# ifdef __linux__
#  define KEY_ESC 65307
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_SPACE 32
# else
#  define KEY_ESC 53
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_SPACE 49
# endif

typedef struct s_app
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*img_sprite_ptr;
	int		*img_pixel_ptr;
	int		bits_per_pixel;
	int		size_line; 
	int		endian;
	int		image_w;
	int		image_h;
	int		x;
	int		y;

} t_app;

int	loop(t_app *app)
{
	mlx_clear_window(app->mlx_ptr, app->win_ptr);
	for (size_t i = 0; i < 100; i++)
	{
		mlx_pixel_put(app->mlx_ptr, app->win_ptr, i + 50, 100, 0xFF0000);
	}
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img_ptr, 300, 350);
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img_sprite_ptr, app->x + 30, app->y + 30);

	return (0);
}

int key_release(int keycode, void *param)
{

	// printf("key code : %d, %c\n", keycode, keycode);
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_UP)
		((t_app *)param)->y -= 5;
	if (keycode == KEY_DOWN)
		((t_app *)param)->y += 5;
	if (keycode == KEY_LEFT)
		((t_app *)param)->x -= 5;
	if (keycode == KEY_RIGHT)
		((t_app *)param)->x += 5;

	return (0);
}

int main(int argc, char** argv)
{
	static t_app	app;

	(void) argc;
	(void) argv;

	app.mlx_ptr = mlx_init();

	app.win_ptr = mlx_new_window(app.mlx_ptr, 640, 480, "test window");

	app.img_sprite_ptr = mlx_xpm_file_to_image(app.mlx_ptr, "images/shield.xpm",
			       &app.image_w, &app.image_h);


	app.img_ptr = mlx_new_image(app.mlx_ptr, 100, 100);

	app.img_pixel_ptr = (int *)mlx_get_data_addr(app.img_ptr, &app.bits_per_pixel,
			   &app.size_line,  &app.endian);

	for (size_t i = 0; i < 100; i++)
		app.img_pixel_ptr[i + 250] = 0x00ff00;

	mlx_loop_hook(app.mlx_ptr, &loop, &app);

	mlx_key_hook(app.win_ptr, &key_release, &app);

	mlx_loop(app.mlx_ptr);

	mlx_destroy_image(app.mlx_ptr, app.img_ptr);
	mlx_destroy_image(app.mlx_ptr, app.img_sprite_ptr);
	
	return (0);
}
