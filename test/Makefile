NAME         = mlx_test

SRCS         = main.c

OBJS         = $(addprefix $(SRC_PATH), $(SRCS:.c=.o))

CC           = gcc

MLX_LIB_PATH = ../lib/
MLX_LIB_NAME = libmlx.a
MLX_LIB      = $(MLX_LIB_PATH)$(MLX_LIB_NAME)
MLX_INCLUDE  = ../include/

CFLAGS       = -Wall -Werror -Wextra -I $(MLX_INCLUDE)

SDL2_LIB     = $(shell sdl2-config --cflags --libs)

all          : $(NAME)


$(NAME)      : $(OBJS)
	$(CC) $^ $(LDFLAGS) -o $(NAME) $(MLX_LIB) $(SDL2_LIB)

clean        :
	rm -f $(OBJS)

fclean       : clean
	rm -f $(NAME)

run          : $(NAME)
	./$(NAME)

re           : fclean all

.PHONY       : clean fclean re $(NAME)

