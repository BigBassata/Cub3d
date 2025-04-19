/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cub.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:54:14 by licohen           #+#    #+#             */
/*   Updated: 2025/04/10 16:03:35 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_CUB_H
# define RENDER_CUB_H

# include "cub3d.h"
# include "struct_cub.h"
# include "parsing_cub.h"

// Hooks
int handle_keypress(int keycode, t_game *game);
int close_window(t_game *game);
int update_loop(t_game *game);

#endif