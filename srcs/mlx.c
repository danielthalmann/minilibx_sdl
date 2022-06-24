/**
 * @file mlx.c
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-11
 *
 */

#include "mlx_internal.h"
#include <signal.h>
#ifdef __WIN32__
    # define SIGQUIT 3
#endif

void	handle_signals(int signum)
{
	if (signum == SIGQUIT)
		SDL_Quit();
}

/**
 * @brief initialize the library
 *
 * @return void*
 */
void	*mlx_init()
{
	static t_mlx	mlx;

    if (!mlx.is_init)
    {
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
            return (NULL);
        }
        mlx.is_init = 1;
    }

	signal(SIGQUIT, handle_signals);

	return (&mlx);
}

int	mlx_do_key_autorepeatoff(void *mlx_ptr)
{
	(void) mlx_ptr;

	return (0);
}

int	mlx_do_key_autorepeaton(void *mlx_ptr)
{
	(void) mlx_ptr;

	return (0);

}

int	mlx_do_sync(void *mlx_ptr)
{
	(void) mlx_ptr;

	return (0);
}
