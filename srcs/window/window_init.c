/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:32:10 by licohen           #+#    #+#             */
/*   Updated: 2025/04/22 16:34:28 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void cleanup_graphics(t_game *game) 
{
	if (game->renderer.frame.img)
		mlx_destroy_image(game->renderer.mlx, game->renderer.frame.img);
	if (game->renderer.win)
		mlx_destroy_window(game->renderer.mlx, game->renderer.win);
}

int init_window(t_game *game)
{
	int screen_width;
	int screen_height;

	mlx_get_screen_size(game->renderer.mlx, &screen_width, &screen_height);
	if (WINDOW_WIDTH > screen_width || WINDOW_HEIGHT > screen_height)
		return (print_error("Window size exceeds screen size"), ERROR);
	game->renderer.win = mlx_new_window(game->renderer.mlx,
		WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	if (!game->renderer.win)
		return (print_error("Failed to create window"), ERROR);    
	game->renderer.frame.img = mlx_new_image(game->renderer.mlx,
		WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->renderer.frame.img)
		return (print_error("Failed to create image"), ERROR);
	game->renderer.frame.addr = mlx_get_data_addr(game->renderer.frame.img,
		&game->renderer.frame.bits_per_pixel,
		&game->renderer.frame.line_length,
		&game->renderer.frame.endian);
	if (!game->renderer.frame.addr)
		return (print_error("Failed to create data addr"), ERROR);
	game->renderer.win_width = (double)WINDOW_WIDTH;
	game->renderer.win_height = (double)WINDOW_HEIGHT;
	init_minimap(game);
	return (TRUE);
}
