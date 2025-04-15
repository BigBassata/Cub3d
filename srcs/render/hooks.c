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

// int	handle_keypress(int keycode, t_data *data)
// {
// 	double moveSpeed = 0.05;
// 	double rotSpeed  = 0.03;

// 	if (keycode == ESCAPE)
// 	{
// 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 		exit(0);
// 	}
// 	else if (keycode == UP)
// 	{
// 		if (worldMap[(int)(data->player.posY)]
// 					[(int)(data->player.posX + data->player.dirX * moveSpeed)] == 0)
// 			data->player.posX += data->player.dirX * moveSpeed;
// 		if (worldMap[(int)(data->player.posY + data->player.dirY * moveSpeed)]
// 					[(int)(data->player.posX)] == 0)
// 			data->player.posY += data->player.dirY * moveSpeed;
// 	}
// 	else if (keycode == DOWN)
// 	{
// 		if (worldMap[(int)(data->player.posY)]
// 					[(int)(data->player.posX - data->player.dirX * moveSpeed)] == 0)
// 			data->player.posX -= data->player.dirX * moveSpeed;
// 		if (worldMap[(int)(data->player.posY - data->player.dirY * moveSpeed)]
// 					[(int)(data->player.posX)] == 0)
// 			data->player.posY -= data->player.dirY * moveSpeed;
// 	}
// 	else if (keycode == ROTATION_LEFT)
// 	{
// 		double oldDirX = data->player.dirX;
// 		data->player.dirX = data->player.dirX * cos(rotSpeed) - data->player.dirY * sin(rotSpeed);
// 		data->player.dirY = oldDirX * sin(rotSpeed) + data->player.dirY * cos(rotSpeed);
// 		double oldPlaneX = data->player.planeX;
// 		data->player.planeX = data->player.planeX * cos(rotSpeed) - data->player.planeY * sin(rotSpeed);
// 		data->player.planeY = oldPlaneX * sin(rotSpeed) + data->player.planeY * cos(rotSpeed);
// 	}
// 	else if (keycode == ROTATION_RIGHT)
// 	{
// 		double oldDirX = data->player.dirX;
// 		data->player.dirX = data->player.dirX * cos(-rotSpeed) - data->player.dirY * sin(-rotSpeed);
// 		data->player.dirY = oldDirX * sin(-rotSpeed) + data->player.dirY * cos(-rotSpeed);
// 		double oldPlaneX = data->player.planeX;
// 		data->player.planeX = data->player.planeX * cos(-rotSpeed) - data->player.planeY * sin(-rotSpeed);
// 		data->player.planeY = oldPlaneX * sin(-rotSpeed) + data->player.planeY * cos(-rotSpeed);
// 	}
// 	else if (keycode == LEFT)
// 	{
// 		// Le vecteur latéral gauche est (-dirY, dirX)
// 		if (worldMap[(int)(data->player.posY)]
// 					[(int)(data->player.posX - data->player.dirY * moveSpeed)] == 0)
// 			data->player.posX -= data->player.dirY * moveSpeed;
// 		if (worldMap[(int)(data->player.posY + data->player.dirX * moveSpeed)]
// 					[(int)(data->player.posX)] == 0)
// 			data->player.posY += data->player.dirX * moveSpeed;
// 	}
// 	else if (keycode == RIGHT)
// 	{
// 		// Le vecteur latéral droit est (dirY, -dirX)
// 		if (worldMap[(int)(data->player.posY)]
// 					[(int)(data->player.posX + data->player.dirY * moveSpeed)] == 0)
// 			data->player.posX += data->player.dirY * moveSpeed;
// 		if (worldMap[(int)(data->player.posY - data->player.dirX * moveSpeed)]
// 					[(int)(data->player.posX)] == 0)
// 			data->player.posY -= data->player.dirX * moveSpeed;
// 	}
// 	return (0);
// }

void	moove_player_up(t_game *game)
{
	double moveSpeed = 0.05;
	double rotSpeed  = 0.03;
	char	**map;

	map = game->map;
	if (map)
	{
		// Fausse variable dir_x et dir_y
		if (map[(int)(game->map_data->player_y)]
			[(int)(game->map_data->player_x + game->map_data->dir_x * moveSpeed)] == 0)
			data->player.posX += data->player.dirX * moveSpeed;

		if (map[(int)(game->map_data->player_y + game->map_data->dir_y * moveSpeed)]
					[(int)(game->map_data->player_x)] == 0)
			data->player.posY += data->player.dirY * moveSpeed;		
	}
}

int	handle_keypress(int keycode, t_game *game)
{
	double moveSpeed = 0.05;
	double rotSpeed  = 0.03;

	if (keycode == ESCAPE)
	{
		cleanup_game(game);
		exit(0);
	}
	else if (keycode == UP)
		moove_player_up(game);
	else if (keycode == UP)
	{
		if (worldMap[(int)(data->player.posY)]
					[(int)(data->player.posX + data->player.dirX * moveSpeed)] == 0)
			data->player.posX += data->player.dirX * moveSpeed;
		if (worldMap[(int)(data->player.posY + data->player.dirY * moveSpeed)]
					[(int)(data->player.posX)] == 0)
			data->player.posY += data->player.dirY * moveSpeed;
	}
	// else if (keycode == DOWN)
	// {
	// 	if (worldMap[(int)(data->player.posY)]
	// 				[(int)(data->player.posX - data->player.dirX * moveSpeed)] == 0)
	// 		data->player.posX -= data->player.dirX * moveSpeed;
	// 	if (worldMap[(int)(data->player.posY - data->player.dirY * moveSpeed)]
	// 				[(int)(data->player.posX)] == 0)
	// 		data->player.posY -= data->player.dirY * moveSpeed;
	// }
	// else if (keycode == ROTATION_LEFT)
	// {
	// 	double oldDirX = data->player.dirX;
	// 	data->player.dirX = data->player.dirX * cos(rotSpeed) - data->player.dirY * sin(rotSpeed);
	// 	data->player.dirY = oldDirX * sin(rotSpeed) + data->player.dirY * cos(rotSpeed);
	// 	double oldPlaneX = data->player.planeX;
	// 	data->player.planeX = data->player.planeX * cos(rotSpeed) - data->player.planeY * sin(rotSpeed);
	// 	data->player.planeY = oldPlaneX * sin(rotSpeed) + data->player.planeY * cos(rotSpeed);
	// }
	// else if (keycode == ROTATION_RIGHT)
	// {
	// 	double oldDirX = data->player.dirX;
	// 	data->player.dirX = data->player.dirX * cos(-rotSpeed) - data->player.dirY * sin(-rotSpeed);
	// 	data->player.dirY = oldDirX * sin(-rotSpeed) + data->player.dirY * cos(-rotSpeed);
	// 	double oldPlaneX = data->player.planeX;
	// 	data->player.planeX = data->player.planeX * cos(-rotSpeed) - data->player.planeY * sin(-rotSpeed);
	// 	data->player.planeY = oldPlaneX * sin(-rotSpeed) + data->player.planeY * cos(-rotSpeed);
	// }
	// else if (keycode == LEFT)
	// {
	// 	// Le vecteur latéral gauche est (-dirY, dirX)
	// 	if (worldMap[(int)(data->player.posY)]
	// 				[(int)(data->player.posX - data->player.dirY * moveSpeed)] == 0)
	// 		data->player.posX -= data->player.dirY * moveSpeed;
	// 	if (worldMap[(int)(data->player.posY + data->player.dirX * moveSpeed)]
	// 				[(int)(data->player.posX)] == 0)
	// 		data->player.posY += data->player.dirX * moveSpeed;
	// }
	// else if (keycode == RIGHT)
	// {
	// 	// Le vecteur latéral droit est (dirY, -dirX)
	// 	if (worldMap[(int)(data->player.posY)]
	// 				[(int)(data->player.posX + data->player.dirY * moveSpeed)] == 0)
	// 		data->player.posX += data->player.dirY * moveSpeed;
	// 	if (worldMap[(int)(data->player.posY - data->player.dirX * moveSpeed)]
	// 				[(int)(data->player.posX)] == 0)
	// 		data->player.posY -= data->player.dirX * moveSpeed;
	// }
	return (0);
}

int	close_window(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}
