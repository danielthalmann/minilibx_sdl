NAME         = libmlx.a

SRCS         = mlx_hook.c \
               mlx_image_png.c \
               mlx_image_xpm.c \
               mlx_image.c \
               mlx_loop.c \
               mlx_mouse.c \
               mlx_string.c \
               mlx_window.c \
               mlx.c \

OBJS         = $(addprefix $(SRC_PATH), $(SRCS:.c=.o))

CC           = gcc

SRC_PATH     = srcs/

LIB          = lib/
INCLUDE      = include/
TEST_PATH    = test/

CFLAGS       = -Wall -Werror -Wextra -I $(INCLUDE)

RM           = rm -f

ifeq ($(OS),Windows_NT)
	RM = cmd //C del
    LIB := $(addsuffix win/, $(LIB))
    CFLAGS += -D WIN32
    ifeq ($(PROCESSOR_ARCHITEW6432),AMD64)
        CFLAGS += -D AMD64
    else
        ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
            CFLAGS += -D AMD64
        endif
        ifeq ($(PROCESSOR_ARCHITECTURE),x86)
            CFLAGS += -D IA32
        endif
    endif
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        LIB := $(addsuffix linux/, $(LIB))
        CFLAGS += -D LINUX
    endif
    ifeq ($(UNAME_S),Darwin)
        LIB := $(addsuffix osx/, $(LIB))
        CFLAGS += -D OSX
    endif
    UNAME_P := $(shell uname -p)
    ifeq ($(UNAME_P),x86_64)
        CFLAGS += -D AMD64
    endif
    ifneq ($(filter %86,$(UNAME_P)),)
        CFLAGS += -D IA32
    endif
    ifneq ($(filter arm%,$(UNAME_P)),)
        CFLAGS += -D ARM
    endif
endif

NAME         := $(addprefix $(LIB), $(NAME))

all          : $(NAME)

$(NAME)      : $(OBJS)
	ar rcs $(NAME) $(OBJS)

test         :
	$(MAKE) -C $(TEST_PATH)
	$(MAKE) run -C $(TEST_PATH)

clean        :
	$(RM) $(OBJS)

fclean       : clean
	$(RM) $(NAME)

re           : fclean all

.PHONY       : clean fclean re test

