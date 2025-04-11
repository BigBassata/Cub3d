/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:48:52 by licohen           #+#    #+#             */
/*   Updated: 2025/04/11 16:34:39 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <stdlib.h>

# include "cub3d.h"

/* Tests de parsing */
void test_is_cub_file(void);
void test_only_spaces_in_line(void);
void test_file_parsing_valid(void);
void test_file_parsing_invalid(void);
void test_get_start_position(void);
void test_parse_map(void);

/* Tests de game */
// void test_init_map(void);
// void test_check_args(void);
// void test_create_trgb(void);
// void test_init_game(void);
// void test_free_2d_array(void);

/* Tests des textures de murs */
void test_config_no_path(void);
void test_config_so_path(void);
void test_config_we_path(void);
void test_config_ea_path(void);
void test_config_f_color(void);
void test_config_c_color(void);
void test_texture_validation(void);
void test_is_complete_config(void);

#endif