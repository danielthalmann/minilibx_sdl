NAME         = libmlx.a

SRCS         = mlx_color.c \
               mlx_event.c \
               mlx_hook.c \
               mlx_image_png.c \
               mlx_image_xpm.c \
               mlx_image.c \
               mlx_key.c \
               mlx_loop.c \
               mlx_mouse.c \
               mlx_string.c \
               mlx_window.c \
               mlx.c \

OBJS         = $(addprefix $(SRC_PATH), $(SRCS:.c=.o))

CC           = gcc

SRC_PATH     = srcs/
OBJS_PATH    = obj/release/

LIB          = lib/
INCLUDE      = include/
TEST_PATH    = test/

CFLAGS       = -Wall -Werror -Wextra -I $(INCLUDE)

ifeq ($(OS),Windows_NT)

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

OBJS         := $(addprefix $(OBJS_PATH), $(OBJS))

ifeq ($(OS),Windows_NT)

    COMMA:= ,
    EMPTY:=
    SPACE:= $(EMPTY) $(EMPTY)
    
    RM_OBJS := PowerShell -Command "Remove-item $(subst $(SPACE), $(COMMA),$(strip $(OBJS)))"
    RM_OUTPUT := PowerShell -Command "Remove-item $(NAME)"
else

    RM_OBJS := rm -f $(OBJS)
    RM_OUTPUT := rm -f $(NAME)

endif

$(addprefix $(OBJS_PATH), %.o): %.c
	$(CC) $(CFLAGS) -o $@ -c $<

all          : $(NAME)

$(NAME)      : $(OBJS)
	ar rcs $(NAME) $(OBJS)

test         :
	$(MAKE) -C $(TEST_PATH)
	$(MAKE) run -C $(TEST_PATH)

clean        :
	- $(RM_OBJS)

fclean       : clean
	- $(RM_OUTPUT)

re           : fclean all

.PHONY       : clean fclean re test

