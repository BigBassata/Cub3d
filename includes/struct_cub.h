/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cub.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:57:47 by licohen           #+#    #+#             */
/*   Updated: 2025/05/02 18:18:28 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_CUB_H
# define STRUCT_CUB_H

# include "cub3d.h"
# include "parsing_cub.h"

enum	e_state
{
	ERROR = -1,
	FALSE,
	TRUE
};

typedef struct s_test_map_node
{
	char					*line;
	struct s_test_map_node	*next;
}	t_test_map_node;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				value;
}	t_color;

/* Structures liées aux images et textures */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_texture
{
	char	*path;
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

/* Structure du joueur */
typedef struct s_player
{
	double	x;
	double	y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}	t_player;

/* Structure de la minimap */
typedef struct s_minimap
{
	int			scale;
	int			width;
	int			height;
	int			pos_x;
	int			pos_y;
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_minimap;

/* Structures liées au raycasting */
typedef struct s_ray
{
	double	ray_angle;
	double	distance;
	int		wall_hit_x;
	int		wall_hit_y;
	int		is_vertical;
	int		facing_up;
	int		facing_right;
}	t_ray;

typedef struct s_dda_data
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_dda_data;

/* Structures liées au rendu */
typedef struct s_renderer
{
	void		*mlx;
	void		*win;
	t_img		frame;
	t_minimap	minimap;
	t_texture	*current_texture;
	int			render_flags;
	int			win_width;
	int			win_height;
}	t_renderer;

typedef struct s_input
{
	int		move_forward;
	int		move_backward;
	int		move_left;
	int		move_right;
	int		rotate_left;
	int		rotate_right;
	int		last_mouse_x;
	int		last_mouse_y;
	double	mouse_sensitivity;
	int 	mouse_capture;
}	t_input;

/* Structure de configuration de la carte (existante) */
typedef struct s_map_config
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

/* Structure des données de la carte */
typedef struct s_map_data
{
	char			**grid;
	int				width;
	int				height;
	char			**flood_grid;
	t_color			floor;
	t_color			ceiling;
	t_texture		north;
	t_texture		south;
	t_texture		east;
	t_texture		west;
	char			player_start_dir;
	double			player_start_x;
	double			player_start_y;
	char			player_dir;
	double			player_x;
	double			player_y;
	t_map_config	*map_config;
}	t_map_data;

typedef struct s_column_render
{
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	t_texture	*texture;
	int			texture_x;
	int			texture_y;
}	t_column_render;

/* Structure principale du jeu */
typedef struct s_game
{
	t_renderer		renderer;
	t_dda_data		dda;
	t_column_render	col_render;
	t_input			input;
	t_map_data		*map_data;
	t_player		player;
	char			**map;
}	t_game;

/* Structures auxiliaires pour le dessin */
typedef struct s_square_data
{
	int	scale;
	int	offset_x;
	int	offset_y;
	int	map_x;
	int	map_y;
	int	color;
}	t_square_data;

typedef struct s_draw_player_data
{
	int			size;
	double		angle;
	int			arrow_x[3];
	int			arrow_y[3];
	t_player	*player;
}	t_draw_player_data;

#endif
