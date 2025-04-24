/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:14:02 by licohen           #+#    #+#             */
/*   Updated: 2025/04/24 18:12:04 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void draw_horizontal_borders(t_game *game)
{
    int x;
    int y;
    int width;
    int i;
    
    width = game->renderer.minimap.width;
    i = 0;
    while (i < BORDER_THICKNESS)
    {
        y = i;
        x = 0;
        while (x < width)
        {
            put_pixel_minimap(game, x, y, MINIMAP_BORDER_COLOR);
            x++;
        }
        y = game->renderer.minimap.height - 1 - i;
        x = 0;
        while (x < width)
        {
            put_pixel_minimap(game, x, y, MINIMAP_BORDER_COLOR);
            x++;
        }
        i++;
    }
}

static void draw_vertical_borders(t_game *game)
{
    int x;
    int y;
    int height;
    int i;
    
    height = game->renderer.minimap.height;
    i = 0;
    while (i < BORDER_THICKNESS)
    {
        x = i;
        y = 0;
        while (y < height)
        {
            put_pixel_minimap(game, x, y, MINIMAP_BORDER_COLOR);
            y++;
        }
        x = game->renderer.minimap.width - 1 - i;
        y = 0;
        while (y < height)
        {
            put_pixel_minimap(game, x, y, MINIMAP_BORDER_COLOR);
            y++;
        }
        i++;
    }
}

void draw_border(t_game *game)
{
    draw_horizontal_borders(game);
    draw_vertical_borders(game);
}
