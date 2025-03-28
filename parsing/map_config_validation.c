/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config_validation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/02/26 18:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	create_game_map(t_map_config *map_config)
{
	char	**game_map;
	int		i;

	if (map_config->map_width < 3 || map_config->map_height < 3)
		return (print_error("map is too small, less than 3x3"), ERROR);
	game_map = malloc((map_config->map_height + 1) * sizeof(char *));
	if (!game_map)
		return (print_error("malloc game map height"), ERROR);
	game_map[map_config->map_height] = NULL;
	i = 0;
	while (i < map_config->map_height)
	{
		game_map[i] = malloc((map_config->map_width + 1) * sizeof(char));
		if (!game_map[i])
			return (free_map(game_map), print_error("malloc game map width"),
				ERROR);
		ft_memset(game_map[i], 0, map_config->map_width + 1);
		i++;
	}
	map_config->map = game_map;
	return (TRUE);
}

int	start_char_nb_validation(t_map_config *map_config)
{
	t_test_map_node	*tmp;
	int				i;
	int				start_chars_nb;

	start_chars_nb = 0;
	tmp = map_config->test_map;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (tmp->line[i] == 'N' || tmp->line[i] == 'S'
				|| tmp->line[i] == 'E' || tmp->line[i] == 'W')
				start_chars_nb++;
			i++;
		}
		tmp = tmp->next;
	}
	if (start_chars_nb < 1)
		return (print_error("missing start character in map: N, S, E or W"),
			ERROR);
	else if (start_chars_nb > 1)
		return (print_error("too many start characters in map"), ERROR);
	return (TRUE);
}

int	game_map_creation(t_map_config *map_config)
{
	if (start_char_nb_validation(map_config) == ERROR)
		return (ERROR);
	get_game_map_size(map_config);
	if (create_game_map(map_config) == ERROR)
		return (ERROR);
	if (fill_game_map(map_config) == ERROR)
		return (ERROR);
	if (get_start_position(map_config) == ERROR)
		return (ERROR);
	transform_spaces_to_void(map_config);
	if (is_map_with_adjacent_walls(map_config) == ERROR)
		return (ERROR);
	if (fill_game_map(map_config) == ERROR)
		return (ERROR);
	transform_spaces_to_walls(map_config);
	if (start_char_inside_walls(map_config) == ERROR)
		return (ERROR);
	transform_spaces_to_walls(map_config);
	if (is_closed_map(map_config) == ERROR)
		return (ERROR);
	return (TRUE);
}

int	is_complete_config(t_map_config *map_config)
{
	if (!map_config->no_path || !map_config->so_path
		|| !map_config->ea_path || !map_config->we_path)
		print_error("Missing wall texture paths in top of .cub file\nusage:"
			"\n\tNO <pathname>\n\tSO <pathname>\n\tWE <pathname>"
			"\n\tEA <pathname>");
	if (map_config->c_color[0] == -1 || map_config->f_color[0] == -1
		|| map_config->c_color[1] == -1 || map_config->f_color[1] == -1
		|| map_config->c_color[2] == -1 || map_config->f_color[2] == -1)
		print_error("Missing RGB colors in top of .cub file\nusage:"
			"\n\tC <r,g,b>\n\tF <r,g,b>");
	if (!map_config->test_map)
		print_error("Missing map in bottom of .cub file");
	if (!map_config->no_path || !map_config->so_path
		|| !map_config->ea_path || !map_config->we_path
		|| map_config->c_color[0] == -1 || map_config->f_color[0] == -1
		|| map_config->c_color[1] == -1 || map_config->f_color[1] == -1
		|| map_config->c_color[2] == -1 || map_config->f_color[2] == -1
		|| !map_config->test_map)
		return (ERROR);
	return (TRUE);
}

int	config_map_validation(t_map_config *map_config)
{
	if (is_complete_config(map_config) == ERROR)
		return (ERROR);
	if (game_map_creation(map_config) == ERROR)
		return (ERROR);
	// ******
	// debug_print_map(map_config);
	// ******
	return (TRUE);
}
