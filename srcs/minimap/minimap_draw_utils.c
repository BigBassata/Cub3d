/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:14:02 by licohen           #+#    #+#             */
/*   Updated: 2025/04/22 15:34:44 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_border(t_game *game)
{
    int angle;
    double rad;
    int r;
    t_point p;

    angle = 0;
    while (angle < 360)
    {
        rad = angle * M_PI / 180;
        r = MINIMAP_RADIUS - BORDER_THICKNESS;
        while (r <= MINIMAP_RADIUS)
        {
            p.x = MINIMAP_RADIUS + r * cos(rad);
            p.y = MINIMAP_RADIUS + r * sin(rad);
            put_pixel_minimap(game, p.x, p.y, MINIMAP_BORDER_COLOR);
            r++;
        }
        angle++;
    }
}
