/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:39:34 by licohen           #+#    #+#             */
/*   Updated: 2025/04/28 16:21:20 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_player_position(t_game *game)
{
	if (game->input.move_forward)
		upward_movement(game);
	if (game->input.move_backward)
		backward_movement(game);
	if (game->input.move_left)
		left_lateral_movement(game);
	if (game->input.move_right)
		right_lateral_movement(game);
	if (game->input.rotate_left)
		left_rotational_movement(game);
	if (game->input.rotate_right)
		right_rotational_movement(game);
}
