NAME         = mlx_test

SRCS         = main.c

OBJS         = $(addprefix $(SRC_PATH), $(SRCS:.c=.o))

CC           = gcc

MLX_LIB_PATH = ../lib/
MLX_LIB_NAME = libmlx.a

CFLAGS       = -Wall -Werror -Wextra


ifeq ($(OS),Windows_NT)
    CFLAGS       += 
    MLX_LIB_PATH := $(addsuffix win/, $(MLX_LIB_PATH))
    SDL2_LIB     = -mwindows -lmingw32 -lSDL2main -lSDL2
else
    UNAME_S      := $(shell uname -s)
    SDL2_LIB     = $(shell sdl2-config --cflags --libs)
    ifeq ($(UNAME_S),Linux)
        MLX_LIB_PATH := $(addsuffix linux/, $(MLX_LIB_PATH))
    endif
    ifeq ($(UNAME_S),Darwin)
        MLX_LIB_PATH := $(addsuffix osx/, $(MLX_LIB_PATH))
    endif
endif

MLX_LIB      = $(MLX_LIB_PATH)$(MLX_LIB_NAME)
MLX_INCLUDE  = ../include/

CFLAGS       += -I $(MLX_INCLUDE)



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

