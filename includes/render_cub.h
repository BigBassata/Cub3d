/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cub.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:54:14 by licohen           #+#    #+#             */
/*   Updated: 2025/05/05 19:48:21 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_CUB_H
# define RENDER_CUB_H

# include "cub3d.h"
# include "struct_cub.h"

// Hooks
int		handle_keypress(int keycode, t_game *game);
int		handle_keyrelease(int keycode, t_game *game);
int		close_window(t_game *game);
int		update_loop(t_game *game);
int		handle_resize(int new_w, int new_h, t_game *game);
int		handle_mouse_move(int x, void *param);

// player
void	config_player(t_game *game);
void	config_starting_dir(t_game *game);
void	config_starting_dir_2(t_game *game);
void	update_player_position(t_game *game);

// render_utils
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
void	config_colors(t_game *game);
void	config_textures(t_game *game);
void	load_texture(t_game *game, t_texture *tex, char *path);
void	render_game(t_game *game);

void	update_walking_animation(t_game *game);
void	draw_ceiling_and_floor_with_bobbing(t_game *game, int x);
void	draw_textured_column_with_bobbing(t_game *game, int x);

// movements
void	upward_movement(t_game *game);
void	backward_movement(t_game *game);
void	left_lateral_movement(t_game *game);
void	right_lateral_movement(t_game *game);
void	left_rotational_movement(t_game *game);
void	right_rotational_movement(t_game *game);
void	rotate_player(t_game *game, double rot_angle);

// raycasting
void	darken_img_between_frame(t_game *game);
void	config_ray_from_camera_x(t_game *game, int x);
void	config_dda_steps_and_sidedist(t_game *game);
void	config_dda_steps_and_sidedist_2(t_game *game);
void	dda_algorithm(t_game *game);
void	handle_fisheye_effect(t_game *game);

void	compute_wall_slice(t_game *game);
void	compute_wall_hit_position(t_game *game);
void	select_texture(t_game *game);
void	compute_texture_x_coord(t_game *game);
void	draw_ceiling_and_floor(t_game *game, int x);
void	draw_textured_column(t_game *game, int x);

/* Minimap */
void	init_minimap(t_game *game);
void	update_minimap(t_game *game);
void	clear_minimap(t_game *game);
void	draw_player(t_game *game);
void	draw_square(t_game *game, int map_x, int map_y, int color);
void	put_pixel_minimap(t_game *game, int x, int y, int color);
void	draw_player_triangle(t_game *game, t_draw_player_data *data);
void	draw_border(t_game *game);
int		is_in_circle(int x, int y, int center_x, int center_y);

#endif
