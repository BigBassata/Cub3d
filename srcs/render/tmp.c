/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
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

// void	config_ray_from_camera_x(t_game *game, int x)
// {
// 	game->dda.camera_x = 2 * x / (double)game->renderer.win_width - 1;
// 	game->dda.ray_dir_x = game->player.dir_x + game->player.plane_x * game->dda.camera_x;
// 	game->dda.ray_dir_y = game->player.dir_y + game->player.plane_y * game->dda.camera_x;
// 	game->dda.map_x = (int)(game->player.pos_x);
// 	game->dda.map_y = (int)(game->player.pos_y);
// 	// if (game->dda.ray_dir_x == 0)
// 	// 	game->dda.delta_dist_x = 1e30;
// 	// else
// 	// 	game->dda.delta_dist_x = fabs(1.0 / game->dda.ray_dir_x);
// 	game->dda.delta_dist_x = (game->dda.ray_dir_x == 0) ? 1e30 : fabs(1.0 / game->dda.ray_dir_x);
// 	// if (game->dda.ray_dir_y == 0)
// 	// 	game->dda.delta_dist_y = 1e30;
// 	// else
// 	// 	game->dda.delta_dist_y = fabs(1.0 / game->dda.ray_dir_y);
// 	game->dda.delta_dist_y = (game->dda.ray_dir_y == 0) ? 1e30 : fabs(1.0 / game->dda.ray_dir_y);
// }

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
	// int map_x;
	// int map_y;
	
	// map_x = game->dda.map_x;
	// map_y = game->dda.map_y;
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
		if (game->map_data->map_config->map[game->dda.map_x][game->dda.map_y] == '1')
			game->dda.hit = 1;
	}
}

// void	handle_fisheye_effect(t_game *game)
// {
// 	double		res;
// 	t_player	p;
// 	t_dda_data	dda;

// 	p = game->player;
// 	dda = game->dda;
// 	if (game->dda.side == 0)
// 	{
// 		res = (dda.map_x - p.pos_x + (1 - dda.step_x) / 2.0) / dda.ray_dir_x;
// 		game->col_render.perp_wall_dist = res;
// 	}
// 	else
// 	{
// 		res = (dda.map_y - p.pos_y + (1 - dda.step_y) / 2.0) / dda.ray_dir_y;
// 		game->col_render.perp_wall_dist = res;
// 	}
// }

void	handle_fisheye_effect(t_game *game)
{
	if (game->dda.side == 0)
		game->col_render.perp_wall_dist = (game->dda.map_x - game->player.pos_x + (1 - game->dda.step_x) / 2.0) / game->dda.ray_dir_x;
	else
		game->col_render.perp_wall_dist = (game->dda.map_y - game->player.pos_y + (1 - game->dda.step_y) / 2.0) / game->dda.ray_dir_y;
}

// int	update_loop(t_game *game)
// {
// 	int		x;

// 	darken_img_between_frame(game);
// 	x = 0;
// 	while (x < game->renderer.win_width)
// 	{
// 		config_ray_from_camera_x(game, x);
// 		config_dda_steps_and_sidedist(game);
// 		dda_algorithm(game);
// 		// Handle Fisheye effect
// 		if (game->dda.side == 0)
// 			game->col_render.perp_wall_dist = (game->dda.map_x - game->player.pos_x + (1 - game->dda.step_x) / 2.0) / game->dda.ray_dir_x;
// 		else
// 			game->col_render.perp_wall_dist = (game->dda.map_y - game->player.pos_y + (1 - game->dda.step_y) / 2.0) / game->dda.ray_dir_y;
		
// 		// line height
// 		game->col_render.line_height = (int)(game->renderer.win_height / game->col_render.perp_wall_dist);

// 		// draw_start and draw_end
// 		game->col_render.draw_start = -game->col_render.line_height / 2 + game->renderer.win_height / 2;
// 		if (game->col_render.draw_start < 0)
// 			game->col_render.draw_start = 0;
// 		game->col_render.draw_end = game->col_render.line_height / 2 + game->renderer.win_height / 2;
// 		if (game->col_render.draw_end >= game->renderer.win_height)
// 			game->col_render.draw_end = game->renderer.win_height - 1;

//         // exact point of impact on the wall (wall_x)
//         double wall_x = (game->dda.side == 0)
//             ? game->player.pos_y + game->col_render.perp_wall_dist * game->dda.ray_dir_y
//             : game->player.pos_x + game->col_render.perp_wall_dist * game->dda.ray_dir_x;
//         wall_x -= floor(wall_x);

//         // select texture
//         t_texture *tex;
//         if (game->dda.side == 0) {
//             tex = game->dda.ray_dir_x > 0 ? &game->map_data->east : &game->map_data->west;
//         } else {
//             tex = game->dda.ray_dir_y > 0 ? &game->map_data->south : &game->map_data->north;
//         }
//         // horizontal coordinate in the texture
//         int tex_x = (int)(wall_x * tex->width);
//         if ((game->dda.side == 0 && game->dda.ray_dir_x > 0) || (game->dda.side == 1 && game->dda.ray_dir_y < 0))
//             tex_x = tex->width - tex_x - 1;

// 		// Ceiling (from y=0 to draw_start-1)
// 		int y = 0;
// 		while (y < game->col_render.draw_start)
// 		{
// 			my_mlx_pixel_put(game, x, y, game->map_data->ceiling.value);
// 			y++;	
// 		}
// 		// Floor (from y=draw_end to WIN_HEIGHT-1)
// 		y = game->col_render.draw_end;
// 		while (y < game->renderer.win_height)
// 		{
// 			my_mlx_pixel_put(game, x, y, game->map_data->floor.value);
// 			y++;		
// 		}

// 		// draw the textured slice
//         for (int y = game->col_render.draw_start; y < game->col_render.draw_end; y++)
//         {
//             int draw_y = y - game->col_render.draw_start;
//             int tex_y = (draw_y * tex->height) / game->col_render.line_height;
//             unsigned int *pixel = 
//                 (unsigned int*)(tex->addr
//                   + tex_y * tex->line_length
//                   + tex_x * (tex->bits_per_pixel/8));
//             my_mlx_pixel_put(game, x, y, *pixel);
//         }
// 		x++;
// 	}
// 	mlx_put_image_to_window(game->renderer.mlx, game->renderer.win,
// 		game->renderer.frame.img, 0, 0);
// 	return (0);
// }

/* LAST OK */
// int	update_loop(t_game *game)
// {
// 	int		x;
// 	double	perp_wall_dist;
// 	int		line_height;
// 	int		draw_start;
// 	int		draw_end;

// 	darken_img_between_frame(game);
// 	x = 0;
// 	while (x < game->renderer.win_width)
// 	{
// 		config_ray_from_camera_x(game, x);
// 		config_dda_steps_and_sidedist(game);
// 		dda_algorithm(game);
// 		// Handle Fisheye effect
// 		if (game->dda.side == 0)
// 			perp_wall_dist = (game->dda.map_x - game->player.pos_x + (1 - game->dda.step_x) / 2.0) / game->dda.ray_dir_x;
// 		else
// 			perp_wall_dist = (game->dda.map_y - game->player.pos_y + (1 - game->dda.step_y) / 2.0) / game->dda.ray_dir_y;
		
// 		// line height
// 		line_height = (int)(game->renderer.win_height / perp_wall_dist);
			
// 		// draw_start and draw_end
// 		draw_start = -line_height / 2 + game->renderer.win_height / 2;
// 		if (draw_start < 0)
// 			draw_start = 0;
// 		draw_end = line_height / 2 + game->renderer.win_height / 2;
// 		if (draw_end >= game->renderer.win_height)
// 			draw_end = game->renderer.win_height - 1;

//         // exact point of impact on the wall (wall_x)
//         double wall_x = (game->dda.side == 0)
//             ? game->player.pos_y + perp_wall_dist * game->dda.ray_dir_y
//             : game->player.pos_x + perp_wall_dist * game->dda.ray_dir_x;
//         wall_x -= floor(wall_x);

//         // select texture
//         t_texture *tex;
//         if (game->dda.side == 0) {
//             tex = game->dda.ray_dir_x > 0 ? &game->map_data->east : &game->map_data->west;
//         } else {
//             tex = game->dda.ray_dir_y > 0 ? &game->map_data->south : &game->map_data->north;
//         }
//         // horizontal coordinate in the texture
//         int tex_x = (int)(wall_x * tex->width);
//         if ((game->dda.side == 0 && game->dda.ray_dir_x > 0) || (game->dda.side == 1 && game->dda.ray_dir_y < 0))
//             tex_x = tex->width - tex_x - 1;

// 		// Ceiling (from y=0 to draw_start-1)
// 		int y = 0;
// 		while (y < draw_start)
// 		{
// 			my_mlx_pixel_put(game, x, y, game->map_data->ceiling.value);
// 			y++;	
// 		}
// 		// Floor (from y=draw_end to WIN_HEIGHT-1)
// 		y = draw_end;
// 		while (y < game->renderer.win_height)
// 		{
// 			my_mlx_pixel_put(game, x, y, game->map_data->floor.value);
// 			y++;		
// 		}

// 		// draw the textured slice
//         for (int y = draw_start; y < draw_end; y++)
//         {
//             int draw_y = y - draw_start;
//             int tex_y = (draw_y * tex->height) / line_height;
//             unsigned int *pixel = 
//                 (unsigned int*)(tex->addr
//                   + tex_y * tex->line_length
//                   + tex_x * (tex->bits_per_pixel/8));
//             my_mlx_pixel_put(game, x, y, *pixel);
//         }
// 		x++;
// 	}
// 	mlx_put_image_to_window(game->renderer.mlx, game->renderer.win,
// 		game->renderer.frame.img, 0, 0);
// 	return (0);
// }
