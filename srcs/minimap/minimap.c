/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:16:56 by licohen           #+#    #+#             */
/*   Updated: 2025/04/22 15:35:14 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void clear_minimap(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->renderer.minimap.height)
    {
        x = 0;
        while (x < game->renderer.minimap.width)
        {
            if (is_in_circle(x, y, MINIMAP_RADIUS, MINIMAP_RADIUS))
                put_pixel_minimap(game, x, y, MINIMAP_BACKGROUND);
            x++;
        }
        y++;
    }
}

static int should_draw_tile(t_game *game, int x, int y)
{
    if (x < 0 || x >= game->map_data->width)
        return (0);
    if (y < 0 || y >= game->map_data->height)
        return (0);
    return (1);
}

static void draw_map_tile(t_game *game, int x, int y)
{
    char tile;

    tile = game->map_data->grid[y][x];
    if (tile == '1')
        draw_square(game, x, y, WALL_COLOR);
    else if (tile == '0' || tile == 'N' || tile == 'S' || 
             tile == 'E' || tile == 'W')
        draw_square(game, x, y, FLOOR_COLOR);
}

void update_minimap(t_game *game)
{
    int view_range;
    int map_x;
    int map_y;
    int x;
    int y;

    view_range = (MINIMAP_RADIUS / game->renderer.minimap.scale) + 1;
    map_x = (int)game->player.pos_x;
    map_y = (int)game->player.pos_y;
    clear_minimap(game);
    y = map_y - view_range;
    while (y <= map_y + view_range)
    {
        x = map_x - view_range;
        while (x <= map_x + view_range)
        {
            if (should_draw_tile(game, x, y))
                draw_map_tile(game, x, y);
            x++;
        }
        y++;
    }
    draw_player(game);
    draw_border(game);
}
