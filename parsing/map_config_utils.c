/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/02/26 18:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_color_arr(int arr[3])
{
	arr[0] = -1;
	arr[1] = -1;
	arr[2] = -1;
}

t_map_config	*init_map_config(void)
{
	t_map_config	*map_config;

	map_config = NULL;
	map_config = malloc(sizeof(t_map_config));
	if (!map_config)
		return (NULL);
	map_config->no_path = NULL;
	map_config->so_path = NULL;
	map_config->we_path = NULL;
	map_config->ea_path = NULL;
	init_color_arr(map_config->f_color);
	init_color_arr(map_config->c_color);
	map_config->map = NULL;
	map_config->test_map = NULL;
	map_config->map_height = -1;
	map_config->map_width = -1;
	map_config->start_dir = 0;
	map_config->start_y = -1;
	map_config->start_x = -1;
	return (map_config);
}

void	free_map(char **map)
{
	char	**tmp;

	if (map)
	{
		tmp = map;
		while (*tmp)
			free(*tmp++);
		free(map);
	}
}

void	delete_map_config(t_map_config *map_config)
{
	if (map_config)
	{
		if (map_config->no_path)
			free(map_config->no_path);
		map_config->no_path = NULL;
		if (map_config->so_path)
			free(map_config->so_path);
		map_config->so_path = NULL;
		if (map_config->we_path)
			free(map_config->we_path);
		map_config->we_path = NULL;
		if (map_config->ea_path)
			free(map_config->ea_path);
		map_config->ea_path = NULL;
		if (map_config->map)
			free_map(map_config->map);
		map_config->map = NULL;
		if (map_config->test_map)
			delete_test_map(map_config->test_map);
		map_config->test_map = NULL;
		free(map_config);
	}
}

void	display_map_config(t_map_config *map_config)
{
	ft_printf("================================\n");
	ft_printf("no_path: %s\n", map_config->no_path);
	ft_printf("so_path: %s\n", map_config->so_path);
	ft_printf("ea_path: %s\n", map_config->ea_path);
	ft_printf("we_path: %s\n", map_config->we_path);
	ft_printf("f_color: %i,%i,%i\n", map_config->f_color[0],
		map_config->f_color[1], map_config->f_color[2]);
	ft_printf("c_color: %i,%i,%i\n", map_config->c_color[0],
		map_config->c_color[1], map_config->c_color[2]);
	ft_printf("map_height: %i\n", map_config->map_height);
	ft_printf("map_width: %i\n", map_config->map_width);
	ft_printf("start_dir: %i\n", map_config->start_dir);
	ft_printf("start_y: %i\n", map_config->start_y);
	ft_printf("start_x: %i\n", map_config->start_x);
	ft_printf("================================\n");
}

void	debug_print_map(t_map_config *map_config)
{
	int	y;
	int	x;
	
	y = 0;
	while (map_config->map[y])
	{
		x = 0;
		while (map_config->map[y][x])
		{
			ft_printf("%c", map_config->map[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}
