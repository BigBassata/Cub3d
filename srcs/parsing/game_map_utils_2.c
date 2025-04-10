/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/02/26 18:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	recursively_check_adjacent_walls(char **map, int y, int x,
	int size[2])
{
	if (y < 0 || x < 0 || y >= size[0] || x >= size[1])
		return (ERROR);
	if (map[y][x] == '1' || map[y][x] == 'v')
		return (TRUE);
	map[y][x] = 'v';
	if (recursively_check_walls(map, y - 1, x, size) != TRUE)
		return (ERROR);
	if (recursively_check_walls(map, y - 1, x - 1, size) != TRUE)
		return (ERROR);
	if (recursively_check_walls(map, y - 1, x + 1, size) != TRUE)
		return (ERROR);
	if (recursively_check_walls(map, y, x - 1, size) != TRUE)
		return (ERROR);
	if (recursively_check_walls(map, y, x + 1, size) != TRUE)
		return (ERROR);
	if (recursively_check_walls(map, y + 1, x, size) != TRUE)
		return (ERROR);
	if (recursively_check_walls(map, y + 1, x - 1, size) != TRUE)
		return (ERROR);
	if (recursively_check_walls(map, y + 1, x + 1, size) != TRUE)
		return (ERROR);
	return (TRUE);
}

int	is_map_with_adjacent_walls(t_map_config *map_config)
{
	int	pos_y;
	int	pos_x;
	int	size[2];

	pos_y = map_config->start_y;
	pos_x = map_config->start_x;
	size[0] = map_config->map_height;
	size[1] = map_config->map_width;
	if (recursively_check_adjacent_walls(map_config->map,
			pos_y, pos_x, size) == ERROR)
		return (print_error("the walls of the map are not adjacent"), ERROR);
	return (TRUE);
}

int	recursively_check_walls(char **map, int y, int x,
	int size[2])
{
	if (y < 0 || x < 0 || y >= size[0] || x >= size[1])
		return (ERROR);
	if (map[y][x] == '1' || map[y][x] == 'v')
		return (TRUE);
	map[y][x] = 'v';
	if (recursively_check_walls(map, y - 1, x, size) != TRUE)
		return (ERROR);
	if (recursively_check_walls(map, y + 1, x, size) != TRUE)
		return (ERROR);
	if (recursively_check_walls(map, y, x - 1, size) != TRUE)
		return (ERROR);
	if (recursively_check_walls(map, y, x + 1, size) != TRUE)
		return (ERROR);
	return (TRUE);
}

int	is_walled_map(t_map_config *map_config)
{
	int	pos_y;
	int	pos_x;
	int	size[2];

	pos_y = map_config->start_y;
	pos_x = map_config->start_x;
	size[0] = map_config->map_height;
	size[1] = map_config->map_width;
	if (recursively_check_walls(map_config->map, pos_y, pos_x, size) == ERROR)
		return (print_error("map is not walled"), ERROR);
	return (TRUE);
}

void	transform_spaces_to_void(t_map_config *map_config)
{
	int	y;
	int	x;

	y = 0;
	while (map_config->map[y])
	{
		x = 0;
		while (map_config->map[y][x])
		{
			if (map_config->map[y][x] == ' ')
				map_config->map[y][x] = '0';
			x++;
		}
		y++;
	}
}
