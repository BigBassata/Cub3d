/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:51:53 by licohen           #+#    #+#             */
/*   Updated: 2025/05/05 20:30:25 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_game_inputs(t_game *game)
{
	game->input.move_forward = 0;
	game->input.move_backward = 0;
	game->input.move_left = 0;
	game->input.move_right = 0;
	game->input.rotate_left = 0;
	game->input.rotate_right = 0;
	game->input.mouse_sensitivity = MOUSE_SENSITIVITY;
	game->input.last_mouse_x = -1;
	game->input.last_mouse_y = -1;
}

static int	init_mlx_engine(t_game *game)
{
	game->renderer.mlx = mlx_init();
	if (!game->renderer.mlx)
	{
		print_error("MLX initialization failed");
		return (FALSE);
	}
	game->renderer.win_width = WINDOW_WIDTH;
	game->renderer.win_height = WINDOW_HEIGHT;
	return (TRUE);
}

static int	init_game_map_data(t_game *game)
{
	game->map_data = init_map();
	if (!game->map_data)
	{
		print_error("Map initialization failed");
		mlx_destroy_display(game->renderer.mlx);
		free(game->renderer.mlx);
		return (FALSE);
	}
	return (TRUE);
}

t_map_data	*init_map(void)
{
	t_map_data	*map;

	map = (t_map_data *)malloc(sizeof(t_map_data));
	if (!map)
	{
		print_error("Memory allocation failed for map data");
		return (NULL);
	}
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

t_game	*init_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		print_error("Memory allocation failed for game structure");
		return (NULL);
	}
	ft_memset(game, 0, sizeof(t_game));
	if (!init_mlx_engine(game))
	{
		free(game);
		return (NULL);
	}
	if (!init_game_map_data(game))
	{
		free(game);
		return (NULL);
	}
	init_game_inputs(game);
	return (game);
}
