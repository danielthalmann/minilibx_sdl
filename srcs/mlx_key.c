/**
 * @file mlx_key.c
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-22
 * 
 */

#include "mlx_internal.h"

int	mlx_keycode_to_mxl_key(SDL_Scancode scancode)
{
	switch (scancode)
	{
	case SDL_SCANCODE_0:
		return (KEY_0);
	case SDL_SCANCODE_1:
		return (KEY_1);
	case SDL_SCANCODE_2:
		return (KEY_2);
	case SDL_SCANCODE_3:
		return (KEY_3);
	case SDL_SCANCODE_4:
		return (KEY_4);
	case SDL_SCANCODE_5:
		return (KEY_5);
	case SDL_SCANCODE_6:
		return (KEY_6);
	case SDL_SCANCODE_7:
		return (KEY_7);
	case SDL_SCANCODE_8:
		return (KEY_8);
	case SDL_SCANCODE_9:
		return (KEY_9);	
	case SDL_SCANCODE_A:
		return (KEY_A);
	case SDL_SCANCODE_B:
		return (KEY_B);
	case SDL_SCANCODE_C:
		return (KEY_C);
	case SDL_SCANCODE_D:
		return (KEY_D);
	case SDL_SCANCODE_E:
		return (KEY_E);
	case SDL_SCANCODE_F:
		return (KEY_F);
	case SDL_SCANCODE_G:
		return (KEY_G);
	case SDL_SCANCODE_H:
		return (KEY_H);
	case SDL_SCANCODE_I:
		return (KEY_I);
	case SDL_SCANCODE_J:
		return (KEY_J);
	case SDL_SCANCODE_K:
		return (KEY_K);
	case SDL_SCANCODE_L:
		return (KEY_L);
	case SDL_SCANCODE_M:
		return (KEY_M);
	case SDL_SCANCODE_N:
		return (KEY_N);
	case SDL_SCANCODE_O:
		return (KEY_O);
	case SDL_SCANCODE_P:
		return (KEY_P);
	case SDL_SCANCODE_Q:
		return (KEY_Q);
	case SDL_SCANCODE_R:
		return (KEY_R);
	case SDL_SCANCODE_S:
		return (KEY_S);
	case SDL_SCANCODE_T:
		return (KEY_T);
	case SDL_SCANCODE_U:
		return (KEY_U);
	case SDL_SCANCODE_V:
		return (KEY_V);
	case SDL_SCANCODE_W:
		return (KEY_W);
	case SDL_SCANCODE_X:
		return (KEY_X);
	case SDL_SCANCODE_Y:
		return (KEY_Y);
	case SDL_SCANCODE_Z:
		return (KEY_Z);
	case SDL_SCANCODE_ESCAPE:
		return (KEY_ESC);
	case SDL_SCANCODE_UP:
		return (KEY_UP);
	case SDL_SCANCODE_DOWN:
		return (KEY_DOWN);
	case SDL_SCANCODE_LEFT:
		return (KEY_LEFT);
	case SDL_SCANCODE_RIGHT:
		return (KEY_RIGHT);
	default:
		return (0);
	}
}
