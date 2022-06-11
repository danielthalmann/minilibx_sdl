/**
 * @file mlx.c
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-11
 * 
 */

#include "mlx.h"
#include "mlx_internal.h"

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
	return (&mlx);
}

