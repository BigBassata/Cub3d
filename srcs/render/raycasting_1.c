/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/04/16 18:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	darken_img_between_frame(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->renderer.win_width * game->renderer.win_height)
	{
		((unsigned int *)game->renderer.frame.addr)[i] = DARKEN_COLOR;
		i++;
	}
}

void	config_ray_from_camera_x(t_game *game, int x)
{
	t_player	p;

	p = game->player;
	game->dda.camera_x = 2 * x / (double)game->renderer.win_width - 1;
	game->dda.ray_dir_x = p.dir_x + p.plane_x * game->dda.camera_x;
	game->dda.ray_dir_y = p.dir_y + p.plane_y * game->dda.camera_x;
	game->dda.map_x = (int)(game->player.pos_x);
	game->dda.map_y = (int)(game->player.pos_y);
	if (game->dda.ray_dir_x == 0)
		game->dda.delta_dist_x = 1e30;
	else
		game->dda.delta_dist_x = fabs(1.0 / game->dda.ray_dir_x);
	if (game->dda.ray_dir_y == 0)
		game->dda.delta_dist_y = 1e30;
	else
		game->dda.delta_dist_y = fabs(1.0 / game->dda.ray_dir_y);
}

void	config_dda_steps_and_sidedist(t_game *game)
{
	double	dist;

	if (game->dda.ray_dir_x < 0)
	{
		game->dda.step_x = -1;
		dist = game->player.pos_x - game->dda.map_x;
		game->dda.side_dist_x = dist * game->dda.delta_dist_x;
	}
	else
	{
		game->dda.step_x = 1;
		dist = game->dda.map_x + 1.0 - game->player.pos_x;
		game->dda.side_dist_x = dist * game->dda.delta_dist_x;
	}
	config_dda_steps_and_sidedist_2(game);
}

void	dda_algorithm(t_game *game)
{
	int	map_x;
	int	map_y;

	game->dda.hit = 0;
	while (game->dda.hit == 0)
	{
		if (game->dda.side_dist_x < game->dda.side_dist_y)
		{
			game->dda.side_dist_x += game->dda.delta_dist_x;
			game->dda.map_x += game->dda.step_x;
			game->dda.side = 0;
		}
		else
		{
			game->dda.side_dist_y += game->dda.delta_dist_y;
			game->dda.map_y += game->dda.step_y;
			game->dda.side = 1;
		}
		map_x = game->dda.map_x;
		map_y = game->dda.map_y;
		if (game->map_data->map_config->map[map_y][map_x] == '1')
			game->dda.hit = 1;
	}
}

void	handle_fisheye_effect(t_game *game)
{
	t_dda_data	d;
	t_player	p;
	double		result;

	d = game->dda;
	p = game->player;
	if (d.side == 0)
	{
		result = (d.map_x - p.pos_x + (1 - d.step_x) / 2.0) / d.ray_dir_x;
		game->col_render.perp_wall_dist = result;
	}
	else
	{
		result = (d.map_y - p.pos_y + (1 - d.step_y) / 2.0) / d.ray_dir_y;
		game->col_render.perp_wall_dist = result;
	}
}
