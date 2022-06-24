/**
 * @file mlx_internal.h
 * @author Daniel Thalmann (daniel@thalmann.li)
 * @date 2022-06-11
 * 
 */

#ifndef MLX_INTERNAL_H
#define	MLX_INTERNAL_H

# define COLOR_BY_PIXEL	4
# define BUFFER_SIZE 512
# define XPM_FILE_HEADER "/* XPM */"

# include "mlx.h"
# include "mlx_key.h"
# include "mlx_event.h"
# include <stdlib.h>
# include <SDL2/SDL.h>

typedef struct s_buffer_read
{
	int		fd;
	int		pos;
	int		pos_end;
	int		size;
	int		last_read;
	char	buffer[BUFFER_SIZE + 1];
}	t_buffer_read;


typedef struct s_list
{
	char			*s;
	struct s_list	*next;
}	t_list;

t_list		*lst_last(t_list *lst);
void		lst_add_back(t_list **alst, t_list *new);
t_list		*lst_new(char *s);
void		lst_del_one(t_list *lst, void (*del)(void*));
void		lst_clear(t_list **lst, void (*del)(void*));
char		**cpy_list_to_char(t_list *list, int list_length);


typedef struct s_xpm_header
{
	int	width;
	int	height;
	int	color_palette;
	int chars_per_pixel;
}	t_xpm_header;

typedef struct s_xpm_color
{
	int	color;
	char *chars_pixel;
}	t_xpm_color;

typedef struct s_xpm
{
	t_xpm_header	header;
	t_xpm_color*	colors;
	char**			image;
}	t_xpm;

int		xpm_set_header(t_xpm *xpm, char *header);
void	xpm_set_colors(t_xpm *xpm, int idx, char *color);

typedef struct s_mlx_window
{
	SDL_Window 			*window;
	SDL_Renderer		*render;
	int 				width;
	int 				height;
	t_event_list		hooks[MLX_MAX_EVENTS];
	struct s_mlx_window	*next;
}	t_mlx_window;

typedef struct s_mlx
{
	int 				is_init;
	int					length;
	int					quit_loop;
	int 				(*loop_funct)(void *);
	void 				*loop_funct_param;
	t_mlx_window		win;
}	t_mlx;

typedef struct s_mlx_img
{
	SDL_Texture		*texture;
	SDL_Renderer	*render;
	int				bpp;
	int				width;
	int				height;
	unsigned char	*data;
}	t_mlx_img;

SDL_Color	mlx_color_create(int color);
void		mlx_refresh_texture(t_mlx_img *img);
int			mlx_raise_expose (t_mlx_window *win_ptr);
int			mlx_raise_keydown(t_mlx_window *win_ptr, SDL_Keysym *keysym);
int			mlx_raise_keyup(t_mlx_window *win_ptr, SDL_Keysym *keysym);
int			mlx_raise_mouseup(t_mlx_window *win_ptr, SDL_MouseButtonEvent *m);
int			mlx_raise_mousedown(t_mlx_window *win_ptr, SDL_MouseButtonEvent *m);
int			mlx_raise_quit(t_mlx_window *win_ptr);
int			mlx_sdl_button_to_mlx_button(int button);
int			mlx_keycode_to_mxl_key(SDL_Scancode scancode);

#endif