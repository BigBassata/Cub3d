/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config_colors_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/02/26 18:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	split_color_line(char *line, t_map_config *map_config, char *color)
{
	char	**splitted_line;
	int		ret_value;

	splitted_line = ft_split(line, ' ');
	if (!splitted_line)
		return (print_error("color format must be: "
				"C <r,g,b> or F <r,g,b>"), ERROR);
	if (!splitted_line[0] || !splitted_line[1])
		return (free_map(splitted_line), print_error("color format must be: "
				"C <r,g,b> or F <r,g,b>"), ERROR);
	if (splitted_line[2] != NULL)
		return (free_map(splitted_line), print_error("color format must be: "
				"C <r,g,b> or F <r,g,b>"), ERROR);
	if (ft_strcmp(splitted_line[0], color) != 0)
		return (free_map(splitted_line), print_error("color format must be: "
				"C <r,g,b> or F <r,g,b>"), ERROR);
	if (*color == 'C')
		ret_value = config_c_color(splitted_line[1], map_config);
	else if (*color == 'F')
		ret_value = config_f_color(splitted_line[1], map_config);
	else
		return (free_map(splitted_line), print_error_arg("no map element find"
				" in parsed line", line), ERROR);
	free_map(splitted_line);
	return (ret_value);
}
