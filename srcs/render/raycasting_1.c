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
	int i;
	
	i = 0;
	while (i < game->renderer.win_width * game->renderer.win_height)
	{
		((unsigned int*)game->renderer.frame.addr)[i] = 0x000000;
		i++;		
	}
}

void	config_ray_from_camera_x(t_game *game, int x)
{
	game->dda.camera_x = 2 * x / (double)game->renderer.win_width - 1;

	game->dda.ray_dir_x = game->player.dir_x + game->player.plane_x * game->dda.camera_x;
	game->dda.ray_dir_y = game->player.dir_y + game->player.plane_y * game->dda.camera_x;

	game->dda.map_x = (int)(game->player.pos_x);
	game->dda.map_y = (int)(game->player.pos_y);

	game->dda.delta_dist_x = (game->dda.ray_dir_x == 0) ? 1e30 : fabs(1.0 / game->dda.ray_dir_x);
	game->dda.delta_dist_y = (game->dda.ray_dir_y == 0) ? 1e30 : fabs(1.0 / game->dda.ray_dir_y);	
}

void	config_dda_steps_and_sidedist(t_game *game)
{
	if (game->dda.ray_dir_x < 0)
	{
		game->dda.step_x = -1;
		game->dda.side_dist_x = (game->player.pos_x - game->dda.map_x) * game->dda.delta_dist_x;
	}
	else
	{
		game->dda.step_x = 1;
		game->dda.side_dist_x = (game->dda.map_x + 1.0 - game->player.pos_x) * game->dda.delta_dist_x;
	}
	if (game->dda.ray_dir_y < 0)
	{
		game->dda.step_y = -1;
		game->dda.side_dist_y = (game->player.pos_y - game->dda.map_y) * game->dda.delta_dist_y;
	}
	else
	{
		game->dda.step_y = 1;
		game->dda.side_dist_y = (game->dda.map_y + 1.0 - game->player.pos_y) * game->dda.delta_dist_y;
	}
}

void	dda_algorithm(t_game *game)
{
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
		if (game->map_data->map_config->map[game->dda.map_y][game->dda.map_x] == '1')
			game->dda.hit = 1;
	}
}

void	handle_fisheye_effect(t_game *game)
{
	if (game->dda.side == 0)
		game->col_render.perp_wall_dist = (game->dda.map_x - game->player.pos_x + (1 - game->dda.step_x) / 2.0) / game->dda.ray_dir_x;
	else
		game->col_render.perp_wall_dist = (game->dda.map_y - game->player.pos_y + (1 - game->dda.step_y) / 2.0) / game->dda.ray_dir_y;	
}

