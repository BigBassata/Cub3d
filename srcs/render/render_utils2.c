/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:53:28 by licohen           #+#    #+#             */
/*   Updated: 2025/05/27 15:53:47 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_x_offset(double dir_x)
{
	if (dir_x > 0)
		return (0.2);
	else
		return (-0.2);
}

double	get_y_offset(double dir_y)
{
	if (dir_y > 0)
		return (0.2);
	else
		return (-0.2);
}

int	is_position_valid(t_game *game, int x, int y)
{
	if (x >= 0 && x < game->map_data->map_config->map_width
		&& y >= 0 && y < game->map_data->map_config->map_height
		&& game->map_data->map_config->map[y][x] == '0')
		return (1);
	return (0);
}
