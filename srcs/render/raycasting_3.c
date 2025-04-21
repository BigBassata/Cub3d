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
	unsigned int	*pixel;
	double			step;
	double			tex_pos;
	int				tex_y;

	step = (double)game->col_render.texture->height
				/ game->col_render.line_height;
	tex_pos = (game->col_render.draw_start
				- game->renderer.win_height / 2
				+ game->col_render.line_height / 2)
				* step;
	y = game->col_render.draw_start;
	while (y < game->col_render.draw_end)
	{
		tex_y = (int)tex_pos & (game->col_render.texture->height - 1);
		tex_pos += step;
		pixel = (unsigned int*)(game->col_render.texture->addr
			+ tex_y * game->col_render.texture->line_length
			+ game->col_render.texture_x
				* (game->col_render.texture->bits_per_pixel / 8));
		my_mlx_pixel_put(game, x, y, *pixel);
		y++;
	}
}
