
#include "mlx.h"

int main(int argc, char** argv)
{
	void	*mlx_ptr;

	void	*mlx_win;

	(void) mlx_win;
	(void) argc;
	(void) argv;

	mlx_ptr = mlx_init();

	mlx_win = mlx_new_window(mlx_ptr, 640, 480, "test window");
	
	mlx_loop(mlx_ptr);
	
	return (0);
}
