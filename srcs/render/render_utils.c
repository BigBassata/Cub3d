/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/04/19 16:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
    char    *dst;
	int		line_length;
	int		bpp;

	line_length = game->renderer.frame.line_length;
	bpp = game->renderer.frame.bits_per_pixel;
    dst = game->renderer.frame.addr + (y * line_length + x * (bpp / 8));
    *(unsigned int*)dst = color;
}

void	config_colors(t_game *game)
{
	int	*c;
	int	*f;

	c = game->map_data->map_config->c_color;
	f = game->map_data->map_config->f_color;
	game->map_data->ceiling.value = 0;
	game->map_data->ceiling.value = (c[0] << 16) | (c[1] << 8) | (c[2]);
	game->map_data->floor.value = 0;
	game->map_data->floor.value = (f[0] << 16) | (f[1] << 8) | (f[2]);
}

void	config_textures(t_game *game)
{
	load_texture(game, &game->map_data->north,
		game->map_data->map_config->no_path);
	load_texture(game, &game->map_data->south,
		game->map_data->map_config->so_path);
	load_texture(game, &game->map_data->east,
		game->map_data->map_config->ea_path);
	load_texture(game, &game->map_data->west,
		game->map_data->map_config->we_path);
}

void load_texture(t_game *game, t_texture *tex, char *path)
{
    tex->img = mlx_xpm_file_to_image(game->renderer.mlx, path, &tex->width,
		&tex->height);
	if (!tex->img)
		clean_error_exit(game, "Failed to create texture image");
    tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
        &tex->line_length, &tex->endian);
	if (!tex->addr)
		clean_error_exit(game, "Failed to create texture data addr");
}

void	render_game(t_game *game)
{
	config_player(game);
	config_colors(game);
	config_textures(game);
	mlx_hook(game->renderer.win, 2, (1L << 0), handle_keypress, game);
	mlx_hook(game->renderer.win, 3, (1L << 1), handle_keyrelease, game);
	mlx_hook(game->renderer.win, 17, 0, close_window, game);
	// mlx_hook(game->renderer.win, 25, 0, handle_resize, game);
	mlx_loop_hook(game->renderer.mlx, update_loop, game);
}