/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/02/26 18:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	transform_spaces_to_walls(t_map_config *map_config)
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
				map_config->map[y][x] = '1';
			x++;
		}
		y++;
	}
}

int	get_start_position(t_map_config *map_config)
{
	int	start_y;
	int	start_x;

	start_y = 0;
	while (map_config->map[start_y])
	{
		start_x = 0;
		while (map_config->map[start_y][start_x])
		{
			if (map_config->map[start_y][start_x] == 'N'
				|| map_config->map[start_y][start_x] == 'S'
				|| map_config->map[start_y][start_x] == 'E'
				|| map_config->map[start_y][start_x] == 'W')
			{
				map_config->start_dir = map_config->map[start_y][start_x];
				map_config->start_y = start_y;
				map_config->start_x = start_x;
				return (TRUE);
			}
			start_x++;
		}
		start_y++;
	}
	return (print_error("no start char find in map"), ERROR);
}

int	start_char_inside_walls(t_map_config *map_config)
{
	int		y;
	int		x;
	char	**map;

	map = map_config->map;
	y = map_config->start_y;
	x = map_config->start_x;
	if (y <= 0 || x <= 0 || y >= map_config->map_height - 1
		|| x >= map_config->map_width - 1)
		return (print_error("bad starting position of char"), ERROR);
	if ((map[y - 1][x - 1] != '1' && map[y - 1][x - 1] != '0')
		|| (map[y - 1][x] != '1' && map[y - 1][x] != '0')
		|| (map[y - 1][x + 1] != '1' && map[y - 1][x + 1] != '0')
		|| (map[y][x - 1] != '1' && map[y][x - 1] != '0')
		|| (map[y][x + 1] != '1' && map[y][x + 1] != '0')
		|| (map[y + 1][x - 1] != '1' && map[y + 1][x - 1] != '0')
		|| (map[y + 1][x] != '1' && map[y + 1][x] != '0')
		|| (map[y + 1][x + 1] != '1' && map[y + 1][x + 1] != '0'))
		return (print_error("bad char around starting position"), ERROR);
	return (TRUE);
}

int	fill_game_map(t_map_config *map_config)
{
	t_test_map_node	*tmp;
	int				i;
	int				height_index;

	tmp = map_config->test_map;
	height_index = 0;
	while (tmp)
	{
		if (height_index >= map_config->map_height)
			return (print_error("bad height size in fill_game_map"), ERROR);
		i = 0;
		while (tmp->line[i])
		{
			if (i >= map_config->map_width)
				return (print_error("bad width size in fill_game_map"), ERROR);
			map_config->map[height_index][i] = tmp->line[i];
			i++;
		}
		while (i < map_config->map_width)
			map_config->map[height_index][i++] = ' ';
		tmp = tmp->next;
		height_index++;
	}
	return (TRUE);
}

void	get_game_map_size(t_map_config *map_config)
{
	t_test_map_node	*tmp;
	int				i;
	int				height;
	int				width;

	height = 0;
	width = 0;
	tmp = map_config->test_map;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i])
		{
			i++;
			if (i > width)
				width = i;
		}
		tmp = tmp->next;
		height++;
	}
	map_config->map_width = width;
	map_config->map_height = height;
}
