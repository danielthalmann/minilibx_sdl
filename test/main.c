
#include "mlx.h"
#include <stdio.h>

typedef struct s_app
{
	void	*mlx_ptr;
	void	*win_ptr;

	void	*img_ptr;
	int		*img_pixel_ptr;
	int		bits_per_pixel;
	int		size_line; 
	int		endian;

} t_app;

int	loop(t_app *app)
{
	mlx_clear_window(app->mlx_ptr, app->win_ptr);
	for (size_t i = 0; i < 100; i++)
	{
		mlx_pixel_put(app->mlx_ptr, app->win_ptr, i + 50, 100, 0xFF0000);
	}
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img_ptr, 5, 10);

	return (0);
}

int main(int argc, char** argv)
{
	t_app	app;

	(void) argc;
	(void) argv;

	app.mlx_ptr = mlx_init();

	app.win_ptr = mlx_new_window(app.mlx_ptr, 640, 480, "test window");

	app.img_ptr = mlx_new_image(app.mlx_ptr, 100, 100);

	app.img_pixel_ptr = (int *)mlx_get_data_addr(app.img_ptr, &app.bits_per_pixel,
			   &app.size_line,  &app.endian);

	for (size_t i = 0; i < 100; i++)
		app.img_pixel_ptr[i + 250] = 0x00ff00;

	mlx_loop_hook (app.mlx_ptr, &loop, &app);
	
	mlx_loop(app.mlx_ptr);

	mlx_destroy_image(app.mlx_ptr, app.img_ptr);
	
	return (0);
}
