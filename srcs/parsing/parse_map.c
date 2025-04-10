/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:52:32 by licohen           #+#    #+#             */
/*   Updated: 2025/04/10 16:10:26 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int copy_map_grid(t_map_data *map_data, t_map_config *map_config)
{
    int i;

    map_data->grid = malloc(sizeof(char *) * (map_data->height + 1));
    if (!map_data->grid)
        return (print_error("Memory allocation failed"), FALSE);
    i = 0;
    while (i < map_data->height)
    {
        map_data->grid[i] = ft_strdup(map_config->map[i]);
        if (!map_data->grid[i])
        {
            free_2d_array(map_data->grid, i);
            return (print_error("Memory allocation failed"), FALSE);
        }
        i++;
    }
    map_data->grid[map_data->height] = NULL;
    return (TRUE);
}

static int copy_texture_paths(t_map_data *map_data, t_map_config *map_config)
{
    map_data->north.path = ft_strdup(map_config->no_path);
    map_data->south.path = ft_strdup(map_config->so_path);
    map_data->east.path = ft_strdup(map_config->ea_path);
    map_data->west.path = ft_strdup(map_config->we_path);
    
    if (!map_data->north.path || !map_data->south.path ||
        !map_data->east.path || !map_data->west.path)
        return (print_error("Failed to copy texture paths"), FALSE);
    return (TRUE);
}

static void setup_colors(t_map_data *map_data, t_map_config *map_config)
{
    map_data->floor.r = map_config->f_color[0];
    map_data->floor.g = map_config->f_color[1];
    map_data->floor.b = map_config->f_color[2];
    map_data->floor.value = create_trgb(0, map_data->floor.r,
                                         map_data->floor.g, map_data->floor.b);
    map_data->ceiling.r = map_config->c_color[0];
    map_data->ceiling.g = map_config->c_color[1];
    map_data->ceiling.b = map_config->c_color[2];
    map_data->ceiling.value = create_trgb(0, map_data->ceiling.r,
                                          map_data->ceiling.g, map_data->ceiling.b);
}

static void setup_player(t_map_data *map_data, t_map_config *map_config)
{
    map_data->player_start_dir = map_config->start_dir;
    map_data->player_start_x = map_config->start_x;
    map_data->player_start_y = map_config->start_y;
}

int parse_map(char *mapfile, t_map_data *map_data)
{
    t_map_config *map_config;

    map_config = file_parsing(mapfile);
    if (!map_config)
        return (print_error("Failed to parse map file"), FALSE);
    map_data->width = map_config->map_width;
    map_data->height = map_config->map_height;
    if (!copy_map_grid(map_data, map_config))
    {
        delete_map_config(map_config);
        return (FALSE);
    }
    if (!copy_texture_paths(map_data, map_config))
    {
        free_2d_array(map_data->grid, map_data->height);
        delete_map_config(map_config);
        return (FALSE);
    }
    setup_colors(map_data, map_config);
    setup_player(map_data, map_config);
    map_data->map_config = map_config;
    return (TRUE);
}
