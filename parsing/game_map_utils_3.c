/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/02/26 18:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_first_line(t_map_config *map_config)
{
	int	i;

	i = 0;
	while (map_config->map[0][i])
	{
		if (map_config->map[0][i++] != '1')
			return (ERROR);
	}
	return (TRUE);
}

int	check_middle_lines(t_map_config *map_config)
{
	int	y;
	int	height;
	int	width;

	height = map_config->map_height;
	width = map_config->map_width;
	y = 1;
	while (y < height - 2)
	{
		if (map_config->map[y][0] != '1'
			|| map_config->map[y][width - 1] != '1')
			return (ERROR);
		y++;
	}
	return (TRUE);
}

int	check_last_line(t_map_config *map_config)
{
	int	i;
	int	last_line;

	i = 0;
	last_line = map_config->map_height - 1;
	while (map_config->map[last_line][i])
	{
		if (map_config->map[last_line][i++] != '1')
			return (ERROR);
	}
	return (TRUE);
}

int	is_closed_map(t_map_config *map_config)
{
	if (check_first_line(map_config) == ERROR)
		return (ERROR);
	if (check_middle_lines(map_config) == ERROR)
		return (ERROR);
	if (check_last_line(map_config) == ERROR)
		return (ERROR);
	return (TRUE);
}
