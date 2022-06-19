![progress](https://img.shields.io/static/v1?label=progress&message=30%&color=orange)
# minilibx_sdl
This is multi platform MinilibX with sdl

## Prerequis

### windows

#### with codeblock

Download and install the last version of codeblock with mingw at url http://www.codeblocks.org/downloads/binaries/

Download and install the last version of lib SDL2.0 at url https://www.libsdl.org/download-2.0.php


#### only with mingw

Follow the video to install mingw at url https://www.youtube.com/watch?v=Zcy981HhGw0

Download and install the last version of lib SDL2.0 at url https://www.libsdl.org/download-2.0.php

### ubuntu

install build essential and sdl2.0 library 

```bash
$ sudo apt install build-essential

$ sudo apt-get install libsdl2-dev
```

### osx

install sdl2.0

```bash
$ brew install sdl2
```

## build

To compile the library, execute this command :

```bash
$ make
```

## test

The test can be executed with :

```bash
$ make test
```

# Progress of developpement

functions that are functional in the library

- [x] mlx_init
- [x] mlx_new_window
- [x] mlx_clear_window
- [x] mlx_pixel_put
- [x] mlx_new_image
- [x] mlx_get_data_addr
- [x] mlx_put_image_to_window
- [ ] mlx_get_color_value
- [ ] mlx_mouse_hook
- [ ] mlx_key_hook
- [ ] mlx_expose_hook
- [x] mlx_loop_hook
- [x] mlx_loop
- [ ] mlx_string_put
- [ ] mlx_xpm_to_image
- [ ] mlx_xpm_file_to_image
- [ ] mlx_png_file_to_image
- [x] mlx_destroy_window
- [x] mlx_destroy_image
- [ ] mlx_hook
- [ ] mlx_mouse_hide
- [ ] mlx_mouse_show
- [ ] mlx_mouse_move
- [ ] mlx_mouse_get_pos
- [ ] mlx_do_key_autorepeatoff
- [ ] mlx_do_key_autorepeaton
- [ ] mlx_do_sync
