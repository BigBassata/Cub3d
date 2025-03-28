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
	t_map_config *map_config;

	if (argc < 2)
		return (0);
	if (argc > 2 || is_cub_file(argv[1]) != TRUE)
		return (print_error("bad args\nusage: ./cub3d <map_name>.cub"), 1);
	map_config = file_parsing(argv[1]);
	if (!map_config)
		return (1);
	delete_map_config(map_config);
	return (0);
}
