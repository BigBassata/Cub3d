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

	int		line_height;

	int		draw_start;
	int		draw_end;

	int i = 0;
    while (i < game->renderer.win_width * game->renderer.win_height)
	{
		((unsigned int*)game->renderer.frame.addr)[i] = 0x000000;
		i++;		
	}

	x = 0;
	while (x < game->renderer.win_width)
	{
		camera_x = 2 * x / (double)game->renderer.win_width - 1;
		// camera_x = 1.0 - 2.0 * x / game->renderer.win_width;

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
			side_dist_y = (game->player.pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - game->player.pos_y) * delta_dist_y;
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
			if (game->map_data->map_config->map[map_y][map_x] == '1')
				hit = 1;
		}
		// Handle Fisheye effect
		if (side == 0)
			perp_wall_dist = (map_x - game->player.pos_x + (1 - step_x) / 2.0) / ray_dir_x;
		else
			perp_wall_dist = (map_y - game->player.pos_y + (1 - step_y) / 2.0) / ray_dir_y;
		
		// line height
		line_height = (int)(game->renderer.win_height / perp_wall_dist);
			
		// draw_start and draw_end
		draw_start = -line_height / 2 + game->renderer.win_height / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + game->renderer.win_height / 2;
		if (draw_end >= game->renderer.win_height)
			draw_end = game->renderer.win_height - 1;

        // exact point of impact on the wall (wall_x)
        double wall_x = (side == 0)
            ? game->player.pos_y + perp_wall_dist * ray_dir_y
            : game->player.pos_x + perp_wall_dist * ray_dir_x;
        wall_x -= floor(wall_x);

        // select texture
        t_texture *tex;
        if (side == 0) {
            tex = ray_dir_x > 0 ? &game->map_data->east : &game->map_data->west;
        } else {
            tex = ray_dir_y > 0 ? &game->map_data->south : &game->map_data->north;
        }
        // horizontal coordinate in the texture
        int tex_x = (int)(wall_x * tex->width);
        if ((side == 0 && ray_dir_x > 0) || (side == 1 && ray_dir_y < 0))
            tex_x = tex->width - tex_x - 1;

		// Ceiling (from y=0 to draw_start-1)
		int y = 0;
		while (y < draw_start)
		{
			my_mlx_pixel_put(game, x, y, game->map_data->ceiling.value);
			y++;	
		}
		// Floor (from y=draw_end to WIN_HEIGHT-1)
		y = draw_end;
		while (y < game->renderer.win_height)
		{
			my_mlx_pixel_put(game, x, y, game->map_data->floor.value);
			y++;		
		}
		// // Red vertical wall, Green horizontal wall
		// int color = (side == 0) ? 0xFF0000 : 0x00FF00;
		// y = draw_start;
		// while (y < draw_end)
		// {
		// 	my_mlx_pixel_put(game, x, y, color);
		// 	y++;
		// }

		// draw the textured slice
        for (int y = draw_start; y < draw_end; y++)
        {
            int draw_y = y - draw_start;
            int tex_y = (draw_y * tex->height) / line_height;
            unsigned int *pixel = 
                (unsigned int*)(tex->addr
                  + tex_y * tex->line_length
                  + tex_x * (tex->bits_per_pixel/8));
            my_mlx_pixel_put(game, x, y, *pixel);
        }
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
