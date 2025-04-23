/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:16:37 by licohen           #+#    #+#             */
/*   Updated: 2025/04/22 16:10:13 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void draw_square_helper(t_game *game, t_square_data *data)
{
    int x;
    int y;
    int screen_x;
    int screen_y;

    y = 0;
    while (y < data->scale)
    {
        x = 0;
        while (x < data->scale)
        {
            screen_x = data->map_x * data->scale + x - data->offset_x;
            screen_y = data->map_y * data->scale + y - data->offset_y;
            put_pixel_minimap(game, screen_x, screen_y, data->color);
            x++;
        }
        y++;
    }
}

static int is_in_player_circle(int x, int y, int center_x, int center_y, int size)
{
	int dist_squared;

	dist_squared = (x - center_x) * (x - center_x) + 
		(y - center_y) * (y - center_y);
	return (dist_squared <= (size / 2) * (size / 2));
}

void draw_square(t_game *game, int map_x, int map_y, int color)
{
    t_square_data data;

    data.scale = game->renderer.minimap.scale;
    data.offset_x = (int)(game->player.pos_x * data.scale) - MINIMAP_RADIUS;
    data.offset_y = (int)(game->player.pos_y * data.scale) - MINIMAP_RADIUS;
    data.map_x = map_x;
    data.map_y = map_y;
    data.color = color;
    draw_square_helper(game, &data);
}

void draw_player(t_game *game)
{
	int size;
	int x;
	int y;
	int center_x;
	int center_y;
	
	size = game->renderer.minimap.scale;
	if (size < 6)
		size = 6;
	center_x = MINIMAP_RADIUS;
	center_y = MINIMAP_RADIUS;
	y = center_y - size / 2;
	while (y <= center_y + size / 2)
	{
		x = center_x - size / 2;
		while (x <= center_x + size / 2)
		{
			if (is_in_player_circle(x, y, center_x, center_y, size))
				put_pixel_minimap(game, x, y, PLAYER_COLOR);
			x++;
		}
		y++;
	}
}
