/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/04/16 18:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESCAPE)
	{
		cleanup_game(game);
		exit(0);
	}
	else if (keycode == UP_Z) // QWERTY = UP, AZERTY = UP_Z
		upward_movement(game);
	else if (keycode == DOWN)
		backward_movement(game);
	else if (keycode == ROTATION_LEFT)
		left_rotational_movement(game);
	else if (keycode == ROTATION_RIGHT)
		right_rotational_movement(game);
	else if (keycode == LEFT_D)  // QWERTY = LEFT, AZERTY = LEFT_D
		left_lateral_movement(game);
	else if (keycode == RIGHT_Q)  // QWERTY = RIGHT, AZERTY = RIGHT_Q
		right_lateral_movement(game);
	return (0);
}

int	close_window(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}

int	update_loop(t_game *game)
{
	int		x;

	darken_img_between_frame(game);
	x = 0;
	while (x < game->renderer.win_width)
	{
		config_ray_from_camera_x(game, x);
		config_dda_steps_and_sidedist(game);
		dda_algorithm(game);
		handle_fisheye_effect(game);
		compute_wall_slice(game);
		compute_wall_hit_position(game);
		select_texture(game);
		compute_texture_x_coord(game);
		draw_ceiling_and_floor(game, x);
		draw_textured_column(game, x);
		x++;
	}
	mlx_put_image_to_window(game->renderer.mlx, game->renderer.win,
		game->renderer.frame.img, 0, 0);
	return (0);
}

int	handle_resize(int new_w, int new_h, t_game *game)
{
	if (new_w < WIN_MIN_WIDTH)  
		new_w = WIN_MIN_WIDTH;
	if (new_h < WIN_MIN_HEIGHT) 
		new_h = WIN_MIN_HEIGHT;
	if (new_w > WIN_MAX_WIDTH)
		new_w = WIN_MAX_WIDTH;
	if (new_h > WIN_MAX_HEIGHT)
		new_h = WIN_MAX_HEIGHT;
	game->renderer.win_width  = new_w;
	game->renderer.win_height = new_h;
	mlx_destroy_image(game->renderer.mlx, game->renderer.frame.img);
	game->renderer.frame.img = mlx_new_image(game->renderer.mlx, new_w, new_h);
	if (!game->renderer.frame.img)
		clean_error_exit(game, "Failed to create image");
	game->renderer.frame.addr = mlx_get_data_addr(game->renderer.frame.img,
		&game->renderer.frame.bits_per_pixel,
		&game->renderer.frame.line_length,
		&game->renderer.frame.endian);
	if (!game->renderer.frame.addr)
		clean_error_exit(game, "Failed to create data addr");
	return (0);
}
