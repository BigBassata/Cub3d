/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config_colors_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/02/26 18:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	cpy_color(int *colors, int *color_index, char *color_str,
	int *str_index)
{
	colors[(*color_index)++] = ft_atoi(color_str);
	ft_memset(color_str, 0, 4);
	*str_index = 0;
}

static int	check_colors_values(int *colors)
{
	if ((colors[0] < 0 || colors[0] > 255)
		|| (colors[1] < 0 || colors[1] > 255)
		|| (colors[2] < 0 || colors[2] > 255))
		return (print_error("All F and C colors values must be from 0 to 255"),
			ERROR);
	return (TRUE);
}

static void	init_config_color_vars(int *var_1, int *var_2, int *var_3,
	char *var_4)
{
	*var_1 = 0;
	*var_2 = 0;
	*var_3 = 0;
	ft_memset(var_4, 0, 4);
}

int	config_f_color(char *line, t_map_config *map_config)
{
	int		i;
	int		f_index;
	int		str_index;
	char	color_str[4];

	if (map_config->f_color[0] != -1)
		return (print_error("F color is already defined"), ERROR);
	init_config_color_vars(&i, &str_index, &f_index, color_str);
	while (line[i])
	{
		if (i > 10 || f_index > 2 || (!ft_isdigit(line[i]) && line[i] != ','))
			return (print_error("color format must be: F <r,g,b>"), ERROR);
		else if (ft_isdigit(line[i]) && str_index < 3)
			color_str[str_index++] = line[i];
		else if (ft_isdigit(line[i]) && str_index >= 3)
			return (print_error("F RGB values must be from 0 to 255"), ERROR);
		if (line[i + 1] == ',' || line[i + 1] == '\0')
			cpy_color(map_config->f_color, &f_index, color_str, &str_index);
		i++;
	}
	return (check_colors_values(map_config->f_color));
}

int	config_c_color(char *line, t_map_config *map_config)
{
	int		i;
	int		c_index;
	int		str_index;
	char	color_str[4];

	if (map_config->c_color[0] != -1)
		return (print_error("C color is already defined"), ERROR);
	init_config_color_vars(&i, &str_index, &c_index, color_str);
	while (line[i])
	{
		if (i > 10 || c_index > 2 || (!ft_isdigit(line[i]) && line[i] != ','))
			return (print_error("color format must be: C <r,g,b>"), ERROR);
		else if (ft_isdigit(line[i]) && str_index < 3)
			color_str[str_index++] = line[i];
		else if (ft_isdigit(line[i]) && str_index >= 3)
			return (print_error("C RGB values must be from 0 to 255"), ERROR);
		if (line[i + 1] == ',' || line[i + 1] == '\0')
			cpy_color(map_config->c_color, &c_index, color_str, &str_index);
		i++;
	}
	return (check_colors_values(map_config->c_color));
}
