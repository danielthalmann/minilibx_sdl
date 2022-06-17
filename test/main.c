
#include "mlx.h"
#include <stdio.h>

typedef struct s_app
{
	void	*mlx_ptr;
	void	*win_ptr;
} t_app;

int	loop(t_app *app)
{
	mlx_clear_window(app->mlx_ptr, app->win_ptr);
	for (size_t i = 0; i < 100; i++)
	{
		mlx_pixel_put(app->mlx_ptr, app->win_ptr, i + 50, 100, 512);
	}
	return (0);
}

int main(int argc, char** argv)
{
	t_app	app;

	(void) argc;
	(void) argv;

	app.mlx_ptr = mlx_init();

	app.win_ptr = mlx_new_window(app.mlx_ptr, 640, 480, "test window");

	mlx_loop_hook (app.mlx_ptr, &loop, &app);
	
	mlx_loop(app.mlx_ptr);
	
	return (0);
}
