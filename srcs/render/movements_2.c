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

void	right_rotational_movement(t_game *game)
{
	double		rot_s;
	double		old_dir_X;
	double		old_plane_X;
	t_player	p;

	p = game->player;
	rot_s  = p.rot_speed;
	old_dir_X = p.dir_x;
	game->player.dir_x = p.dir_x * cos(-rot_s) - p.dir_y * sin(-rot_s);
	game->player.dir_y = old_dir_X * sin(-rot_s) + p.dir_y * cos(-rot_s);
	old_plane_X = p.plane_x;
	game->player.plane_x = p.plane_x * cos(-rot_s) - p.plane_y * sin(-rot_s);
	game->player.plane_y = old_plane_X * sin(-rot_s) + p.plane_y * cos(-rot_s);
}
