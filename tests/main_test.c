/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:46:40 by licohen           #+#    #+#             */
/*   Updated: 2025/04/11 16:59:50 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Déclarations des fonctions de test
// Tests de parsing
extern void test_is_cub_file(void);
extern void test_only_spaces_in_line(void);
extern void test_file_parsing_valid(void);
extern void test_file_parsing_invalid(void);
extern void test_get_start_position(void);
extern void test_parse_map(void);

void setUp(void) {
    // Code d'initialisation avant chaque test
}

void tearDown(void) {
    // Code de nettoyage après chaque test
}

// Fonction pour désactiver temporairement les messages d'erreur pendant les tests
static void silence_output(void) {
    // Rediriger stderr vers /dev/null
    freopen("/dev/null", "w", stderr);
}

// Fonction pour restaurer les messages d'erreur
static void restore_output(void) {
    // Restaurer stderr
    freopen("/dev/tty", "w", stderr);
}

int main(void) 
{
    UNITY_BEGIN();
    
    // Tests de parsing
    printf("\n=== TESTS DE PARSING ===\n");
    
    // Validation de noms de fichiers
    RUN_TEST(test_is_cub_file);
    RUN_TEST(test_only_spaces_in_line);
    
    // Tests du parsing de fichier
    silence_output(); // On désactive temporairement les messages d'erreur pour ces tests
    RUN_TEST(test_file_parsing_valid);
    RUN_TEST(test_file_parsing_invalid);
    RUN_TEST(test_get_start_position);
    RUN_TEST(test_parse_map);
    restore_output();
    
    return UNITY_END();
}