/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:51:53 by licohen           #+#    #+#             */
/*   Updated: 2025/04/11 16:55:14 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map_data *init_map(void)
{
    t_map_data *map;

    map = (t_map_data *)malloc(sizeof(t_map_data));
    if (!map)
        return (print_error("Memory allocation failed for map data"), NULL);
    ft_memset(map, 0, sizeof(t_map_data));
    map->floor.r = -1;
    map->floor.g = -1;
    map->floor.b = -1;
    map->ceiling.r = -1;
    map->ceiling.g = -1;
    map->ceiling.b = -1;
    map->player_start_x = -1;
    map->player_start_y = -1;
    map->player_x = -1;
    map->player_y = -1;
    
    return (map);
}

t_game *init_game(void)
{
	t_game *game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (print_error("Memory allocation failed for game structure"), NULL);
	ft_memset(game, 0, sizeof(t_game));
	game->renderer.mlx = mlx_init();
	if (!game->renderer.mlx)
	{
		free(game);
		return (print_error("MLX initialization failed"), NULL);
	}
	game->state.is_running = 1;
	game->state.window_focused = 1;
    game->state.last_frame = get_time();
    game->input.mouse_sensitivity = MOUSE_SENSITIVITY;
    game->map_data = init_map();
    if (!game->map_data)
    {
        mlx_destroy_display(game->renderer.mlx);
        free(game->renderer.mlx);
        free(game);
        return (print_error("Map initialization failed"), NULL);
    }
    return (game);
}
