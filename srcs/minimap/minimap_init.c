/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:11:35 by licohen           #+#    #+#             */
/*   Updated: 2025/04/28 16:01:42 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_minimap(t_game *game)
{
	t_minimap	*minimap;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

	if (!game)
		clean_error_exit(game, "Erreur lors de l'initialisation de la minimap");
	minimap = &game->renderer.minimap;
	ft_memset(minimap, 0, sizeof(t_minimap));
	minimap->width = 150;
	minimap->height = 150;
	minimap->scale = MINIMAP_SCALE;
	minimap->pos_x = 20;
	minimap->pos_y = 20;
	minimap->img = mlx_new_image(game->renderer.mlx,
			minimap->width, minimap->height);
	if (!minimap->img)
		clean_error_exit(game, "Erreur création image minimap");
	minimap->addr = (int *)mlx_get_data_addr(minimap->img, &bits_per_pixel,
			&line_length, &endian);
	if (!minimap->addr)
		clean_error_exit(game, "Erreur adresse données minimap");
	minimap->bits_per_pixel = bits_per_pixel;
	minimap->line_length = line_length;
	minimap->endian = endian;
}

int	is_in_circle(int x, int y, int center_x, int center_y)
{
	int	dx;
	int	dy;

	dx = x - center_x;
	dy = y - center_y;
	return (dx * dx + dy * dy <= MINIMAP_RADIUS * MINIMAP_RADIUS);
}

void	put_pixel_minimap(t_game *game, int x, int y, int color)
{
	t_minimap	*minimap;
	int			index;

	minimap = &game->renderer.minimap;
	if (x < 0 || x >= minimap->width || y < 0 || y >= minimap->height)
		return ;
	index = y * (minimap->line_length / 4) + x;
	minimap->addr[index] = color;
}
