/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:47:45 by licohen           #+#    #+#             */
/*   Updated: 2025/04/08 15:16:29 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

static void free_texture(t_texture *texture, void *mlx)
{
    if (!texture)
        return;
    if (texture->path)
    {
        free(texture->path);
        texture->path = NULL;
    }
    if (texture->img && mlx)
    {
        mlx_destroy_image(mlx, texture->img);
        texture->img = NULL;
        texture->addr = NULL;
    }
}

static void free_textures(t_map_data *map, void *mlx)
{
    if (!map)
        return;
    free_texture(&map->north, mlx);
    free_texture(&map->south, mlx);
    free_texture(&map->east, mlx);
    free_texture(&map->west, mlx);
}

static void free_renderer(t_renderer *renderer)
{
    if (!renderer)
        return;
    if (renderer->frame.img)
        mlx_destroy_image(renderer->mlx, renderer->frame.img);
    if (renderer->minimap.img)
        mlx_destroy_image(renderer->mlx, renderer->minimap.img);
    if (renderer->win)
        mlx_destroy_window(renderer->mlx, renderer->win);
    if (renderer->mlx)
    {
        mlx_destroy_display(renderer->mlx);
        free(renderer->mlx);
    }
}

void clean_map_data(t_map_data *map, void *mlx)
{
    if (!map)
        return;
    if (map->grid)
    {
        free_2d_array(map->grid, map->height);
        map->grid = NULL;
    }
    if (map->flood_grid)
    {
        free_2d_array(map->flood_grid, map->height);
        map->flood_grid = NULL;
    }
    free_textures(map, mlx);
    if (map->map_config)
        delete_map_config(map->map_config);
    free(map);
}

void cleanup_game(t_game *game)
{
    if (!game)
        return;
    if (game->map_data)
        clean_map_data(game->map_data, game->renderer.mlx);
    free_renderer(&game->renderer);
    free(game);
}
