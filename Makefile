NAME         = libmlx.a

SRCS         = mlx.c \
               mlx_loop.c \
               mlx_window.c \

OBJS         = $(addprefix $(SRC_PATH), $(SRCS:.c=.o))

CC           = gcc

SRC_PATH     = srcs/

LIB          = lib/
INCLUDE      = include/
TEST_PATH    = test/

CFLAGS       = -Wall -Werror -Wextra -I $(INCLUDE)

all          : $(NAME)


$(NAME)      : $(OBJS)
	ar rcs $(addprefix $(LIB), $(NAME)) $(OBJS)

test         :
	$(MAKE) -C $(TEST_PATH)
	$(MAKE) run -C $(TEST_PATH)

clean        :
	rm -f $(OBJS)

fclean       : clean
	rm -f $(NAME)

re           : fclean all

.PHONY       : clean fclean re test

