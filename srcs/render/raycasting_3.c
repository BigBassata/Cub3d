/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/04/16 18:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_textured_column(t_game *game, int x)
{
	int				y;
	int				delta_y;
	unsigned int	*pixel;

	y = game->col_render.draw_start;
	while (y < game->col_render.draw_end)
	{
		delta_y = y - game->col_render.draw_start;
		game->col_render.texture_y = (delta_y * game->col_render.texture->height) / game->col_render.line_height;
		pixel = 
			(unsigned int*)(game->col_render.texture->addr
			+ game->col_render.texture_y * game->col_render.texture->line_length
			+ game->col_render.texture_x * (game->col_render.texture->bits_per_pixel/8));
		my_mlx_pixel_put(game, x, y, *pixel);
		y++;
	}
}
