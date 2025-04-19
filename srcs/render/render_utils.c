/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/04/19 16:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
    char    *dst;
	int		line_length;
	int		bpp;

	line_length = game->renderer.frame.line_length;
	bpp = game->renderer.frame.bits_per_pixel;
    dst = game->renderer.frame.addr + (y * line_length + x * (bpp / 8));
    *(unsigned int*)dst = color;
}
