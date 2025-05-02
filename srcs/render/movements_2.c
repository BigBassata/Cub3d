/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/04/16 18:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	left_rotational_movement(t_game *game)
{
	rotate_player(game, game->player.rot_speed);
}

void	right_rotational_movement(t_game *game)
{
	rotate_player(game, -game->player.rot_speed);
}

void	rotate_player(t_game *game, double rot_angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rot_angle)
		- game->player.dir_y * sin(rot_angle);
	game->player.dir_y = old_dir_x * sin(rot_angle)
		+ game->player.dir_y * cos(rot_angle);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rot_angle)
		- game->player.plane_y * sin(rot_angle);
	game->player.plane_y = old_plane_x * sin(rot_angle)
		+ game->player.plane_y * cos(rot_angle);
}
