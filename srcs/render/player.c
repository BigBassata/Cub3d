/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/04/19 16:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	config_starting_dir(t_game *game)
{
	if (game->map_data->player_start_dir == 'N')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = 1.0;
	}
	else if (game->map_data->player_start_dir == 'S')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = -1.0;	
	}
	else if (game->map_data->player_start_dir == 'E')
	{
		game->player.dir_x = 1.0;
		game->player.dir_y = 0.0;
	}
	else if (game->map_data->player_start_dir == 'W')
	{
		game->player.dir_x = -1.0;
		game->player.dir_y = 0.0;
	}
}

void	config_player(t_game *game)
{
	game->player.pos_x = game->map_data->player_start_x + 0.5;
	game->player.pos_y = game->map_data->player_start_y + 0.5;
	game->player.plane_x = PLANE_X;
	game->player.plane_y = PLANE_Y;
	config_starting_dir(game);
}
