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

// void	moove_player_up(t_game *game)
// {
// 	double moveSpeed = 0.05;
// 	double rotSpeed  = 0.03;
// 	char	**map;

// 	map = game->map;
// 	if (map)
// 	{
// 		// Fausse variable dir_x et dir_y
// 		if (map[(int)(game->map_data->player_y)]
// 			[(int)(game->map_data->player_x + game->map_data->dir_x * moveSpeed)] == 0)
// 			data->player.posX += data->player.dirX * moveSpeed;

// 		if (map[(int)(game->map_data->player_y + game->map_data->dir_y * moveSpeed)]
// 					[(int)(game->map_data->player_x)] == 0)
// 			data->player.posY += data->player.dirY * moveSpeed;		
// 	}
// }

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESCAPE)
	{
		cleanup_game(game);
		exit(0);
	}
	return (0);
}

// int	handle_keypress(int keycode, t_game *game)
// {
	// double moveSpeed = 0.05;
	// double rotSpeed  = 0.03;

	// if (keycode == ESCAPE)
	// {
	// 	cleanup_game(game);
	// 	exit(0);
	// }
// 	else if (keycode == UP)
// 		moove_player_up(game);
// 	else if (keycode == UP)
// 	{
// 		if (worldMap[(int)(data->player.posY)]
// 					[(int)(data->player.posX + data->player.dirX * moveSpeed)] == 0)
// 			data->player.posX += data->player.dirX * moveSpeed;
// 		if (worldMap[(int)(data->player.posY + data->player.dirY * moveSpeed)]
// 					[(int)(data->player.posX)] == 0)
// 			data->player.posY += data->player.dirY * moveSpeed;
// 	}
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
// 	return (0);
// }

int	close_window(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}

int	update_loop(t_game *game)
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_X;
	double	delta_dist_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;

	int		hit;
	int		side; // 0 : vertical wall, 1 : horizontal wall

	double	perp_wall_dist;

	x = 0;
	while (x < game->renderer.win_width)
	{
		camera_x = 2 * x / game->renderer.win_width - 1;

		ray_dir_x = game->player.dir_x + game->player.plane_x * camera_x;
		ray_dir_y = game->player.dir_y + game->player.plane_y * camera_x;

		map_x = (int)(game->player.pos_x);
		map_y = (int)(game->player.pos_y);

		delta_dist_X = (ray_dir_x == 0) ? 1e30 : fabs(1.0 / ray_dir_x);
		delta_dist_y = (ray_dir_y == 0) ? 1e30 : fabs(1.0 / ray_dir_y);

        if (ray_dir_x < 0)
        {
            step_x = -1;
            side_dist_x = (game->player.pos_x - map_x) * delta_dist_X;
        }
        else
        {
            step_x = 1;
            side_dist_x = (map_x + 1.0 - game->player.pos_x) * delta_dist_X;
        }
        if (ray_dir_y < 0)
        {
            step_y = -1;
            side_dist_y = (data->player.posY - map_y) * delta_dist_y;
        }
        else
        {
            step_y = 1;
            side_dist_y = (map_y + 1.0 - data->player.posY) * delta_dist_y;
        }
		x++;
	}
	// DDA algorithm
	hit = 0;
	while (hit == 0)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_X;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = 1;
		}
		if (game->map[map_y][map_x] > 0)
			hit = 1;
	}
	// Handle Fisheye effect
	if (side == 0)
		perp_wall_dist = (map_x - game->player.pos_x + (1 - step_x) / 2.0) / ray_dir_x;
	else
		perp_wall_dist = (map_y - game->player.pos_y + (1 - step_y) / 2.0) / ray_dir_y;
	mlx_put_image_to_window(game->renderer.mlx, game->renderer.win,
		game->renderer.frame.img, 0, 0);
	return (0);
}
