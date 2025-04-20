/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/02/26 18:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "parsing_cub.h"
# include "render_cub.h"
# include "struct_cub.h"
# include "test.h"
# include "../Unity/src/unity.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

# define EXIT_WIN 17
# define ESCAPE 65307

# define UP_Z 119
# define LEFT_D 100
# define RIGHT_Q 113

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ROTATION_LEFT 65363
# define ROTATION_RIGHT 65361

/* Player settings */
# define PLANE_X 0.0
# define PLANE_Y 0.66

/* Mouse Settings */
# define MOUSE_SENSITIVITY 0.0003
# define MOUSE_CAPTURE_KEY 109
# define MOUSE_DEADZONE 2

/* Window */
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define WIN_MIN_WIDTH 320
# define WIN_MIN_HEIGHT 240
# define WIN_MAX_WIDTH 1920
# define WIN_MAX_HEIGHT 1080
# define EXTENSION_NAME ".cub"
# define WINDOW_NAME "cub3D"

//utils
void			print_error(char *error);
void			print_error_arg(char *error, char *arg);
void 			free_2d_array(char **array, int height);
double	        get_time(void);
int             create_trgb(int t, int r, int g, int b);

// utils_2
void            clean_error_exit(t_game *game, char *error);

// cleanup fonctions
void 			clean_map_data(t_map_data *map, void *mlx);
void 			cleanup_game(t_game *game);
void            cleanup_graphics(t_game *game);


int 			check_args(char *mapfile, int argc);
t_map_data      *init_map(void);
int             init_window(t_game *game);
t_game          *init_game(void);



#endif