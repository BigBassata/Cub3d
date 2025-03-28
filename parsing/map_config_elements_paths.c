/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config_elements_paths.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/02/26 18:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	texture_file_validation(char *path)
{
	int	texture_file_fd;
	int	len;

	texture_file_fd = open(path, O_RDONLY);
	if (texture_file_fd < 0)
		return (print_error_arg("invalid texture file: ", path), ERROR);
	close(texture_file_fd);
	len = ft_strlen(path);
	if (len < 5)
		return (print_error_arg("invalid file format, usage"
				"<filename>.png\n", path), ERROR);
	if (path[len - 5] == '/' || ft_strncmp(&path[len - 4], ".png", 4) != 0)
		return (print_error_arg("invalid file format, usage"
				"<filename>.png\n", path), ERROR);
	return (TRUE);
}

int	config_no_path(char *line, t_map_config *map_config)
{
	char	**splitted_line;

	if (map_config->no_path)
		return (print_error("NO path is already defined"), ERROR);
	splitted_line = ft_split(line, ' ');
	if (!splitted_line)
		return (print_error("map element format, "
				"usage: NO <path_to_texture>"), ERROR);
	if (!splitted_line[0] || !splitted_line[1])
		return (free_map(splitted_line), print_error("map element format, "
				"usage: NO <path_to_texture>"), ERROR);
	if (splitted_line[2] != NULL)
		return (free_map(splitted_line), print_error("map element format, "
				"usage: NO <path_to_texture>"), ERROR);
	if (ft_strcmp(splitted_line[0], "NO") != 0)
		return (free_map(splitted_line), print_error("map element format, "
				"usage: NO <path_to_texture>"), ERROR);
	map_config->no_path = ft_strdup(splitted_line[1]);
	free_map(splitted_line);
	if (!map_config->no_path)
		return (print_error("ft_strdup in config_no_path"), ERROR);
	if (texture_file_validation(map_config->no_path) == ERROR)
		return (ERROR);
	return (TRUE);
}

int	config_so_path(char *line, t_map_config *map_config)
{
	char	**splitted_line;

	if (map_config->so_path)
		return (print_error("SO path is already defined"), ERROR);
	splitted_line = ft_split(line, ' ');
	if (!splitted_line)
		return (print_error("map element format, "
				"usage: SO <path_to_texture>"), ERROR);
	if (!splitted_line[0] || !splitted_line[1])
		return (free_map(splitted_line), print_error("map element format, "
				"usage: SO <path_to_texture>"), ERROR);
	if (splitted_line[2] != NULL)
		return (free_map(splitted_line), print_error("map element format, "
				"usage: SO <path_to_texture>"), ERROR);
	if (ft_strcmp(splitted_line[0], "SO") != 0)
		return (free_map(splitted_line), print_error("map element format, "
				"usage: SO <path_to_texture>"), ERROR);
	map_config->so_path = ft_strdup(splitted_line[1]);
	free_map(splitted_line);
	if (!map_config->so_path)
		return (print_error("ft_strdup in config_so_path"), ERROR);
	if (texture_file_validation(map_config->so_path) == ERROR)
		return (ERROR);
	return (TRUE);
}

int	config_we_path(char *line, t_map_config *map_config)
{
	char	**splitted_line;

	if (map_config->we_path)
		return (print_error("WE path is already defined"), ERROR);
	splitted_line = ft_split(line, ' ');
	if (!splitted_line)
		return (print_error("map element format, "
				"usage: WE <path_to_texture>"), ERROR);
	if (!splitted_line[0] || !splitted_line[1])
		return (free_map(splitted_line), print_error("map element format, "
				"usage: WE <path_to_texture>"), ERROR);
	if (splitted_line[2] != NULL)
		return (free_map(splitted_line), print_error("map element format, "
				"usage: WE <path_to_texture>"), ERROR);
	if (ft_strcmp(splitted_line[0], "WE") != 0)
		return (free_map(splitted_line), print_error("map element format, "
				"usage: WE <path_to_texture>"), ERROR);
	map_config->we_path = ft_strdup(splitted_line[1]);
	free_map(splitted_line);
	if (!map_config->we_path)
		return (print_error("ft_strdup in config_we_path"), ERROR);
	if (texture_file_validation(map_config->we_path) == ERROR)
		return (ERROR);
	return (TRUE);
}

int	config_ea_path(char *line, t_map_config *map_config)
{
	char	**splitted_line;

	if (map_config->ea_path)
		return (print_error("EA path is already defined"), ERROR);
	splitted_line = ft_split(line, ' ');
	if (!splitted_line)
		return (print_error("map element format, "
				"usage: EA <path_to_texture>"), ERROR);
	if (!splitted_line[0] || !splitted_line[1])
		return (free_map(splitted_line), print_error("map element format, "
				"usage: EA <path_to_texture>"), ERROR);
	if (splitted_line[2] != NULL)
		return (free_map(splitted_line), print_error("map element format, "
				"usage: EA <path_to_texture>"), ERROR);
	if (ft_strcmp(splitted_line[0], "EA") != 0)
		return (free_map(splitted_line), print_error("map element format, "
				"usage: EA <path_to_texture>"), ERROR);
	map_config->ea_path = ft_strdup(splitted_line[1]);
	free_map(splitted_line);
	if (!map_config->ea_path)
		return (print_error("ft_strdup in config_ea_path"), ERROR);
	if (texture_file_validation(map_config->ea_path) == ERROR)
		return (ERROR);
	return (TRUE);
}
