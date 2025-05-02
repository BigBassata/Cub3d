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

void	upward_movement(t_game *game)
{
	double		move_speed;
	t_player	p;
	int			next_x;
	int			next_y;

	p = game->player;
	move_speed = p.move_speed;
	next_x = (int)(p.pos_x + p.dir_x * move_speed);
	next_y = (int)p.pos_y;
	if (next_x >= 0 && next_x < game->map_data->map_config->map_width
		&& next_y >= 0 && next_y < game->map_data->map_config->map_height
		&& game->map_data->map_config->map[next_y][next_x] == '0')
		game->player.pos_x += p.dir_x * move_speed;
	next_x = (int)p.pos_x;
	next_y = (int)(p.pos_y + p.dir_y * move_speed);
	if (next_x >= 0 && next_x < game->map_data->map_config->map_width
		&& next_y >= 0 && next_y < game->map_data->map_config->map_height
		&& game->map_data->map_config->map[next_y][next_x] == '0')
		game->player.pos_y += p.dir_y * move_speed;
}

void	backward_movement(t_game *game)
{
	double		move_speed;
	t_player	p;
	int			next_x;
	int			next_y;

	move_speed = game->player.move_speed;
	p = game->player;
	next_x = (int)(p.pos_x - p.dir_x * move_speed);
	next_y = (int)p.pos_y;
	if (next_x >= 0 && next_x < game->map_data->map_config->map_width
		&& next_y >= 0 && next_y < game->map_data->map_config->map_height
		&& game->map_data->map_config->map[next_y][next_x] == '0')
		game->player.pos_x -= p.dir_x * move_speed;
	next_x = (int)p.pos_x;
	next_y = (int)(p.pos_y - p.dir_y * move_speed);
	if (next_x >= 0 && next_x < game->map_data->map_config->map_width
		&& next_y >= 0 && next_y < game->map_data->map_config->map_height
		&& game->map_data->map_config->map[next_y][next_x] == '0')
		game->player.pos_y -= p.dir_y * move_speed;
}

void	left_lateral_movement(t_game *game)
{
	double		move_speed;
	t_player	p;
	int			next_x;
	int			next_y;

	move_speed = game->player.move_speed;
	p = game->player;
	next_x = (int)(p.pos_x - p.dir_y * move_speed);
	next_y = (int)(p.pos_y);
	if (next_x >= 0 && next_x < game->map_data->map_config->map_width
		&& next_y >= 0 && next_y < game->map_data->map_config->map_height
		&& game->map_data->map_config->map[next_y][next_x] == '0')
		game->player.pos_x -= p.dir_y * move_speed;
	next_x = (int)(p.pos_x);
	next_y = (int)(p.pos_y + p.dir_x * move_speed);
	if (next_x >= 0 && next_x < game->map_data->map_config->map_width
		&& next_y >= 0 && next_y < game->map_data->map_config->map_height
		&& game->map_data->map_config->map[next_y][next_x] == '0')
		game->player.pos_y += p.dir_x * move_speed;
}

void	right_lateral_movement(t_game *game)
{
	double		move_speed;
	t_player	p;
	int			next_x;
	int			next_y;

	move_speed = game->player.move_speed;
	p = game->player;
	next_x = (int)(p.pos_x + p.dir_y * move_speed);
	next_y = (int)(p.pos_y);
	if (next_x >= 0 && next_x < game->map_data->map_config->map_width
		&& next_y >= 0 && next_y < game->map_data->map_config->map_height
		&& game->map_data->map_config->map[next_y][next_x] == '0')
		game->player.pos_x += p.dir_y * move_speed;
	next_x = (int)(p.pos_x);
	next_y = (int)(p.pos_y - p.dir_x * move_speed);
	if (next_x >= 0 && next_x < game->map_data->map_config->map_width
		&& next_y >= 0 && next_y < game->map_data->map_config->map_height
		&& game->map_data->map_config->map[next_y][next_x] == '0')
		game->player.pos_y -= p.dir_x * move_speed;
}
