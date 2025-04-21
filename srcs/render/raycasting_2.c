/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/04/16 18:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	compute_wall_slice(t_game *game)
{
	game->col_render.line_height = (int)(game->renderer.win_height / game->col_render.perp_wall_dist);
	game->col_render.draw_start = -game->col_render.line_height / 2 + game->renderer.win_height / 2;
	if (game->col_render.draw_start < 0)
		game->col_render.draw_start = 0;
	game->col_render.draw_end = game->col_render.line_height / 2 + game->renderer.win_height / 2;
	if (game->col_render.draw_end >= game->renderer.win_height)
		game->col_render.draw_end = game->renderer.win_height - 1;
}

void	compute_wall_hit_position(t_game *game)
{
	game->col_render.wall_x = (game->dda.side == 0)
		? game->player.pos_y + game->col_render.perp_wall_dist * game->dda.ray_dir_y
		: game->player.pos_x + game->col_render.perp_wall_dist * game->dda.ray_dir_x;
	game->col_render.wall_x -= floor(game->col_render.wall_x);
}

void	select_texture(t_game *game)
{
	if (game->dda.side == 0) {
		game->col_render.texture = game->dda.ray_dir_x > 0 ? &game->map_data->east : &game->map_data->west;
	} else {
		game->col_render.texture = game->dda.ray_dir_y > 0 ? &game->map_data->south : &game->map_data->north;
	}
}

void	compute_texture_x_coord(t_game *game)
{
	game->col_render.texture_x = (int)(game->col_render.wall_x * game->col_render.texture->width);
	if ((game->dda.side == 0 && game->dda.ray_dir_x > 0) || (game->dda.side == 1 && game->dda.ray_dir_y < 0))
		game->col_render.texture_x = game->col_render.texture->width - game->col_render.texture_x - 1;	
}

void	draw_ceiling_and_floor(t_game *game, int x)
{
	int y;

	y = 0;
	while (y < game->col_render.draw_start)
	{
		my_mlx_pixel_put(game, x, y, game->map_data->ceiling.value);
		y++;	
	}
	y = game->col_render.draw_end;
	while (y < game->renderer.win_height)
	{
		my_mlx_pixel_put(game, x, y, game->map_data->floor.value);
		y++;		
	}
}
