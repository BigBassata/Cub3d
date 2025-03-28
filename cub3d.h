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

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"

# define EXIT_WIN 17
# define ESCAPE 65307

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

enum e_state
{
	ERROR = -1,
	FALSE,
	TRUE
};

typedef struct	s_test_map_node
{
	char					*line;
	struct s_test_map_node	*next;
}	t_test_map_node;

typedef struct	s_map_config
{
	char					*no_path;
	char					*so_path;
	char					*we_path;
	char					*ea_path;
	int						f_color[3];
	int						c_color[3];
	char					**map;
	struct s_test_map_node	*test_map;
	int						map_height;
	int						map_width;
	char					start_dir;
	int						start_y;
	int						start_x;
}	t_map_config;

/* -------------------- */
/* ------ ERROR ------- */
/* -------------------- */

// error.c
void			print_error(char *error);
void			print_error_arg(char *error, char *arg);

/* ---------------------- */
/* ------ PARSING ------- */
/* ---------------------- */

// file validation.c
int				is_cub_file(char *file);

// file_parsing_1.c
t_map_config	*file_parsing(char *file);
int				config_map(int fd, t_map_config *map_config);
int				dispatch_line(char *line, t_map_config *map_config);
int				config_map_elements(char *line, t_map_config *map_config);
int				test_map_creation(char *line, t_map_config *map_config);

// file_parsing_2.c
int				only_spaces_in_line(char *line);

// map_config_utils.c
t_map_config	*init_map_config(void);
void			free_map(char **map);
void			delete_map_config(t_map_config *map_config);

// test_map_utils.c
int				add_test_map_node(char *line, t_map_config *map_config);
void			delete_test_map(t_test_map_node *test_map);

// map_config_elements_paths.c 
int				config_no_path(char *line, t_map_config *map_config);
int				config_so_path(char *line, t_map_config *map_config);
int				config_we_path(char *line, t_map_config *map_config);
int				config_ea_path(char *line, t_map_config *map_config);

// map_config_colors_1.c
int				config_f_color(char *line, t_map_config *map_config);
int				config_c_color(char *line, t_map_config *map_config);

// map_config_colors_2.c
int				split_color_line(char *line, t_map_config *map_config,
					char *color);

// map_config_validation.c
int				config_map_validation(t_map_config *map_config);
int				is_complete_config(t_map_config *map_config);
int				game_map_creation(t_map_config *map_config);
int				start_char_nb_validation(t_map_config *map_config);
int				create_game_map(t_map_config *map_config);

// game_map_utils_1.c
void			get_game_map_size(t_map_config *map_config);
int				fill_game_map(t_map_config *map_config);
int				get_start_position(t_map_config *map_config);
int				start_char_inside_walls(t_map_config *map_config);
void			transform_spaces_to_walls(t_map_config *map_config);

// game_map_utils_2.c
int				is_walled_map(t_map_config *map_config);
void			transform_spaces_to_void(t_map_config *map_config);
int				recursively_check_walls(char **map, int y, int x,
					int size[2]);
int				is_map_with_adjacent_walls(t_map_config *map_config);
int				recursively_check_adjacent_walls(char **map, int y, int x,
					int size[2]);

// game_map_utils_3.c
int				check_first_line(t_map_config *map_config);
int				check_middle_lines(t_map_config *map_config);
int				check_last_line(t_map_config *map_config);
int				is_closed_map(t_map_config *map_config);

/**** DEV ****/
void			display_map_config(t_map_config *map_config);
void			debug_print_map(t_map_config *map_config);

#endif