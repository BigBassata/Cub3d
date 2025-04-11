/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:08:11 by licohen           #+#    #+#             */
/*   Updated: 2025/04/11 16:55:12 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Fonction pour tester is_cub_file
void test_is_cub_file(void)
{
    // Test avec un fichier .cub valide
    TEST_ASSERT_EQUAL(TRUE, is_cub_file("maps/linux_maps/map_valid_1.cub"));
    
    // Tests avec des fichiers invalides
    TEST_ASSERT_EQUAL(FALSE, is_cub_file("maps/linux_maps/map_invalid_name_1.cu"));
    TEST_ASSERT_EQUAL(FALSE, is_cub_file("maps/linux_maps/map_invalid_name_2.cuba"));
    TEST_ASSERT_EQUAL(FALSE, is_cub_file(".cub")); // Fichier trop court
    TEST_ASSERT_EQUAL(FALSE, is_cub_file("test")); // Pas d'extension
    TEST_ASSERT_EQUAL(FALSE, is_cub_file("test.txt")); // Extension incorrecte
}

// Fonction pour tester only_spaces_in_line
void test_only_spaces_in_line(void)
{
    TEST_ASSERT_EQUAL(TRUE, only_spaces_in_line("    "));
    TEST_ASSERT_EQUAL(TRUE, only_spaces_in_line(" "));
    TEST_ASSERT_EQUAL(FALSE, only_spaces_in_line("  1  "));
    TEST_ASSERT_EQUAL(FALSE, only_spaces_in_line("Hello"));
    TEST_ASSERT_EQUAL(FALSE, only_spaces_in_line(" N "));
}

// Fonction pour tester file_parsing avec différents fichiers
void test_file_parsing_valid(void)
{
    // Test avec un fichier valide
    t_map_config *config = file_parsing("maps/linux_maps/map_valid_1.cub");
    TEST_ASSERT_NOT_NULL(config);
    
    // Vérification des valeurs du config
    TEST_ASSERT_NOT_NULL(config->no_path);
    TEST_ASSERT_NOT_NULL(config->so_path);
    TEST_ASSERT_NOT_NULL(config->we_path);
    TEST_ASSERT_NOT_NULL(config->ea_path);
    
    // Vérification des couleurs
    TEST_ASSERT_EQUAL(0, config->c_color[0]);
    TEST_ASSERT_EQUAL(0, config->c_color[1]);
    TEST_ASSERT_EQUAL(0, config->c_color[2]);
    
    TEST_ASSERT_EQUAL(120, config->f_color[0]);
    TEST_ASSERT_EQUAL(120, config->f_color[1]);
    TEST_ASSERT_EQUAL(120, config->f_color[2]);
    
    // Vérification de la map
    TEST_ASSERT_NOT_NULL(config->map);
    TEST_ASSERT_GREATER_THAN(0, config->map_height);
    TEST_ASSERT_GREATER_THAN(0, config->map_width);
    
    // Nettoyage
    delete_map_config(config);
}

void test_file_parsing_invalid(void)
{
    // Tests avec différents fichiers invalides
    TEST_ASSERT_NULL(file_parsing("maps/linux_maps/map_invalid_void_file.cub"));
    TEST_ASSERT_NULL(file_parsing("maps/linux_maps/map_invalid_only_NO.cub"));
    TEST_ASSERT_NULL(file_parsing("maps/linux_maps/map_invalid_only_Map.cub"));
    TEST_ASSERT_NULL(file_parsing("maps/linux_maps/map_invalid_incomplete_colors.cub"));
    TEST_ASSERT_NULL(file_parsing("fichier_inexistant.cub"));
}

// Tests pour get_start_position
void test_get_start_position(void)
{
    t_map_config *config = file_parsing("maps/linux_maps/map_valid_1.cub");
    TEST_ASSERT_NOT_NULL(config);
    
    // Le jeu de test devrait déjà avoir trouvé la position de départ
    TEST_ASSERT_EQUAL('N', config->start_dir);
    TEST_ASSERT_NOT_EQUAL(-1, config->start_x);
    TEST_ASSERT_NOT_EQUAL(-1, config->start_y);
    
    // Nettoyage
    delete_map_config(config);
}

// Fonction pour vérifier parse_map complet
void test_parse_map(void)
{
    t_map_data *map_data = init_map();
    TEST_ASSERT_NOT_NULL(map_data);
    
    // Test avec un fichier valide
    TEST_ASSERT_EQUAL(TRUE, parse_map("maps/linux_maps/map_valid_1.cub", map_data));
    
    // Vérification des données de la map
    TEST_ASSERT_NOT_NULL(map_data->grid);
    TEST_ASSERT_GREATER_THAN(0, map_data->width);
    TEST_ASSERT_GREATER_THAN(0, map_data->height);
    
    // Vérification des textures
    TEST_ASSERT_NOT_NULL(map_data->north.path);
    TEST_ASSERT_NOT_NULL(map_data->south.path);
    TEST_ASSERT_NOT_NULL(map_data->east.path);
    TEST_ASSERT_NOT_NULL(map_data->west.path);
    
    // Vérification des couleurs
    TEST_ASSERT_EQUAL(120, map_data->floor.r);
    TEST_ASSERT_EQUAL(120, map_data->floor.g);
    TEST_ASSERT_EQUAL(120, map_data->floor.b);
    
    TEST_ASSERT_EQUAL(0, map_data->ceiling.r);
    TEST_ASSERT_EQUAL(0, map_data->ceiling.g);
    TEST_ASSERT_EQUAL(0, map_data->ceiling.b);
    
    // Nettoyage
    clean_map_data(map_data, NULL);
    
    // Test avec un fichier invalide
    map_data = init_map();
    TEST_ASSERT_NOT_NULL(map_data);
    TEST_ASSERT_EQUAL(FALSE, parse_map("maps/linux_maps/map_invalid_void_file.cub", map_data));
    clean_map_data(map_data, NULL);
}
