/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/02/26 18:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (check_args(argv[1], argc) != TRUE)
		return (1);
	game = init_game();
	if (!game)
		return (print_error("Memory allocation failed"), 1);
	if (parse_map(argv[1], game->map_data) != TRUE)
		return (cleanup_game(game), 1);
	if (!init_window(game))
	{
		cleanup_game(game);
		return (print_error("Window initialization failed"), 1);
	}
	render_game(game);
	mlx_loop(game->renderer.mlx);
	return (0);
}
