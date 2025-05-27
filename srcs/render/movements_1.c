/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/04/16 18:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	try_move(t_game *game, double dx, double dy, double speed)
{
	int	next_x;
	int	next_y;

	next_x = (int)(game->player.pos_x + dx * speed + get_x_offset(dx));
	next_y = (int)game->player.pos_y;
	if (is_position_valid(game, next_x, next_y))
		game->player.pos_x += dx * speed;
	next_x = (int)game->player.pos_x;
	next_y = (int)(game->player.pos_y + dy * speed + get_y_offset(dy));
	if (is_position_valid(game, next_x, next_y))
		game->player.pos_y += dy * speed;
}

void	upward_movement(t_game *game)
{
	t_player	p;

	p = game->player;
	try_move(game, p.dir_x, p.dir_y, p.move_speed);
}

void	backward_movement(t_game *game)
{
	t_player	p;

	p = game->player;
	try_move(game, -p.dir_x, -p.dir_y, p.move_speed);
}

void	left_lateral_movement(t_game *game)
{
	t_player	p;

	p = game->player;
	try_move(game, -p.dir_y, p.dir_x, p.move_speed);
}

void	right_lateral_movement(t_game *game)
{
	t_player	p;

	p = game->player;
	try_move(game, p.dir_y, -p.dir_x, p.move_speed);
}
