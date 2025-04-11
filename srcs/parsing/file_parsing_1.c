/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/02/26 18:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	test_map_creation(char *line, t_map_config *map_config)
{
	int	i;

	if (map_config->test_map
		&& (line[0] == '\0' || only_spaces_in_line(line)) == TRUE)
		return (print_error("empty line not allowed after map"), ERROR);
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'W'
			&& line[i] != 'E')
			return (print_error("char not allowed in map"), ERROR);
		i++;
	}
	return (add_test_map_node(line, map_config));
}

int	config_map_elements(char *line, t_map_config *map_config)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_strncmp(&line[i], "NO", 2) == 0)
		return (config_no_path(line, map_config));
	else if (ft_strncmp(&line[i], "SO", 2) == 0)
		return (config_so_path(line, map_config));
	else if (ft_strncmp(&line[i], "WE", 2) == 0)
		return (config_we_path(line, map_config));
	else if (ft_strncmp(&line[i], "EA", 2) == 0)
		return (config_ea_path(line, map_config));
	else if (ft_strncmp(&line[i], "F", 1) == 0)
		return (split_color_line(line, map_config, "F"));
	else if (ft_strncmp(&line[i], "C", 1) == 0)
		return (split_color_line(line, map_config, "C"));
	else
		return (print_error("only map elements and empty lines are allowed"),
			ERROR);
	return (TRUE);
}

int	dispatch_line(char *line, t_map_config *map_config)
{
	if (!map_config->no_path || !map_config->so_path
		|| !map_config->ea_path || !map_config->we_path
		|| map_config->c_color[0] == -1 || map_config->f_color[0] == -1)
	{
		if (config_map_elements(line, map_config) == ERROR)
			return (ERROR);
	}
	else
	{
		if (test_map_creation(line, map_config) == ERROR)
			return (ERROR);
	}
	return (TRUE);
}

int	config_map(int fd, t_map_config *map_config)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if ((line[0] == '\r' && line[1] == '\n') || line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		line = ft_strtrim(line, "\r\n");
		if (!line)
			return (print_error("ft_strtrim in config_map failed"), ERROR);
		if (dispatch_line(line, map_config) == ERROR)
			return (free(line), ERROR);
		free(line);
		line = get_next_line(fd);
	}
	return (TRUE);
}

t_map_config	*file_parsing(char *file)
{
	t_map_config	*map_config;
	int				fd;

	map_config = init_map_config();
	if (!map_config)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_error("fd opening failed"), NULL);
	if (config_map(fd, map_config) != TRUE)
		return (close(fd), delete_map_config(map_config), NULL);
	if (config_map_validation(map_config) != TRUE)
		return (close(fd), delete_map_config(map_config), NULL);
	printf("color: %d %d %d\n", map_config->f_color[0],
		map_config->f_color[1], map_config->f_color[2]);
	return (close(fd), map_config);
}
