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

#ifndef CUB3D_H
#define CUB3D_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

# define EXIT_WIN 17
# define ESCAPE 65307

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

/* Mouse Settings */
# define MOUSE_SENSITIVITY 0.0003
# define MOUSE_CAPTURE_KEY 109
# define MOUSE_DEADZONE 2


enum e_state
{
	ERROR = -1,
	FALSE,
	TRUE
};

typedef struct	s_test_map_node
{
	char					*line;
	struct s_test_map_node	*next;
}	t_test_map_node;

/* Structures basiques */
typedef struct s_dims
{
    int width;
    int height;
} t_dims;

typedef struct s_point
{
    int x;
    int y;
} t_point;

typedef struct s_color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    int value;      // Valeur combinée pour un accès rapide
} t_color;

/* Structures liées aux images et textures */
typedef struct s_img
{
    void *img;
    int *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_img;

typedef struct s_texture
{
    char *path;           // Chemin vers le fichier de texture
    void *img;            // Pointeur vers l'image MLX
    int *addr;            // Adresse des données de l'image
    int width;
    int height;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_texture;

/* Structure du joueur */
typedef struct s_player
{
    double x;             // Position X dans la grille
    double y;             // Position Y dans la grille
    double pos_x;         // Position X pour le rendu
    double pos_y;         // Position Y pour le rendu
    double dir_x;         // Direction X (vecteur de direction)
    double dir_y;         // Direction Y (vecteur de direction)
    double plane_x;       // Plan de caméra X (vecteur perpendiculaire)
    double plane_y;       // Plan de caméra Y (vecteur perpendiculaire)
    double move_speed;    // Vitesse de déplacement
    double rot_speed;     // Vitesse de rotation
    int move_forward;     // État du mouvement vers l'avant
    int move_backward;    // État du mouvement vers l'arrière
    int move_left;        // État du mouvement latéral gauche
    int move_right;       // État du mouvement latéral droit
    int rotate_left;      // État de la rotation gauche
    int rotate_right;     // État de la rotation droite
    int rotation_direction; // Direction de rotation (-1, 0, 1)
} t_player;

/* Structure de la minimap */
typedef struct s_minimap
{
    int scale;            // Échelle de la minimap par rapport à la grille
    int width;            // Largeur en pixels
    int height;           // Hauteur en pixels
    int pos_x;            // Position X dans la fenêtre
    int pos_y;            // Position Y dans la fenêtre
    void *img;            // Pointeur vers l'image MLX
    int *addr;            // Adresse des données de l'image
    int bits_per_pixel;
    int line_length;
    int endian;
} t_minimap;

/* Structures liées au raycasting */
typedef struct s_ray
{
    double ray_angle;     // Angle du rayon
    double distance;      // Distance au mur
    int wall_hit_x;       // Position X du point d'impact
    int wall_hit_y;       // Position Y du point d'impact
    int is_vertical;      // Si le mur touché est vertical
    int facing_up;        // Si le rayon pointe vers le haut
    int facing_right;     // Si le rayon pointe vers la droite
} t_ray;

typedef struct s_wall_render
{
    int wall_height;      // Hauteur du mur à l'écran
    int wall_top;         // Coordonnée Y du haut du mur
    int wall_bottom;      // Coordonnée Y du bas du mur
    double wall_x;        // Position X exacte du point d'impact (pour texture)
    int tex_x;            // Coordonnée X dans la texture
    double step;          // Pas de texture par pixel
    double tex_pos;       // Position actuelle dans la texture
    double shade;         // Facteur d'ombrage (distance)
    int tex_y;            // Coordonnée Y dans la texture
    t_player *player;     // Référence au joueur
} t_wall_render;

typedef struct s_color_data
{
    int ceiling_color;    // Couleur du plafond
    int floor_color;      // Couleur du sol
    unsigned int color;   // Couleur de travail
    unsigned char r;      // Composante rouge
    unsigned char g;      // Composante verte
    unsigned char b;      // Composante bleue
} t_color_data;

typedef struct s_dda_data
{
    double ray_dir_x;     // Direction X du rayon
    double ray_dir_y;     // Direction Y du rayon
    double delta_dist_x;  // Distance entre intersections verticales
    double delta_dist_y;  // Distance entre intersections horizontales
    int map_x;            // Position X dans la grille
    int map_y;            // Position Y dans la grille
    double side_dist_x;   // Distance à la prochaine intersection verticale
    double side_dist_y;   // Distance à la prochaine intersection horizontale
    int step_x;           // Direction de pas en X (-1, 0, 1)
    int step_y;           // Direction de pas en Y (-1, 0, 1)
} t_dda_data;

/* Structures liées au rendu */
typedef struct s_renderer
{
    void *mlx;            // Pointeur MLX
    void *win;            // Pointeur vers la fenêtre
    t_img frame;          // Image principale pour le rendu
    t_minimap minimap;    // Minimap
    t_texture *current_texture; // Texture actuelle en cours d'utilisation
    int render_flags;     // Drapeaux pour les options de rendu
} t_renderer;

/* Structures de gestion des états du jeu */
typedef struct s_game_state
{
    int is_running;       // Si le jeu est en cours d'exécution
    int window_focused;   // Si la fenêtre a le focus
    int mouse_captured;   // Si la souris est capturée
    double last_frame;    // Temps du dernier frame
    double delta_time;    // Temps entre les frames
    double fps;           // Frames par seconde
    int status_anim_frame; // Frame d'animation pour les statuts
    int status_transitioning; // Si une transition est en cours
} t_game_state;

typedef struct s_input
{
    int move_forward;     // Touche W
    int move_backward;    // Touche S
    int move_left;        // Touche A
    int move_right;       // Touche D
    int rotate_left;      // Flèche gauche
    int rotate_right;     // Flèche droite
    int last_mouse_x;     // Dernière position X de la souris
    int last_mouse_y;     // Dernière position Y de la souris
    double mouse_sensitivity; // Sensibilité de la souris
} t_input;

/* Structure de configuration de la carte (existante) */
typedef struct s_map_config
{
    char *no_path;        // Chemin de la texture Nord
    char *so_path;        // Chemin de la texture Sud
    char *we_path;        // Chemin de la texture Ouest
    char *ea_path;        // Chemin de la texture Est
    int f_color[3];       // Couleur du sol (RGB)
    int c_color[3];       // Couleur du plafond (RGB)
    char **map;           // Grille de la carte
    struct s_test_map_node *test_map;  // Liste chaînée temporaire pour parser la carte
    int map_height;       // Hauteur de la carte
    int map_width;        // Largeur de la carte
    char start_dir;       // Direction de départ du joueur (N, S, E, W)
    int start_y;          // Position Y de départ du joueur
    int start_x;          // Position X de départ du joueur
} t_map_config;

/* Structure des données de la carte */
typedef struct s_map_data
{
    char **grid;          // Grille de la carte (0 = vide, 1 = mur, etc.)
    int width;            // Largeur de la grille
    int height;           // Hauteur de la grille
    char **flood_grid;    // Grille utilisée pour la vérification par inondation
    t_color floor;        // Couleur du sol
    t_color ceiling;      // Couleur du plafond
    t_texture north;      // Texture pour les murs orientés nord
    t_texture south;      // Texture pour les murs orientés sud
    t_texture east;       // Texture pour les murs orientés est
    t_texture west;       // Texture pour les murs orientés ouest
    char player_start_dir; // Direction initiale du joueur
    double player_start_x; // Position X initiale du joueur
    double player_start_y; // Position Y initiale du joueur
    char player_dir;      // Direction actuelle du joueur
    double player_x;      // Position X actuelle du joueur
    double player_y;      // Position Y actuelle du joueur
    t_map_config *map_config; // Pointeur vers la configuration originale
} t_map_data;

/* Structure principale du jeu */
typedef struct s_game
{
    t_renderer renderer;  // Gestionnaire de rendu
    t_game_state state;   // État du jeu
    t_input input;        // Gestion des entrées
    t_map_data *map_data; // Données de la carte
    t_player player;      // Données du joueur
    char **map;           // Référence à la grille pour un accès rapide
    double move_speed;    // Vitesse de déplacement (peut être ajustée)
} t_game;

/* Structures auxiliaires pour le dessin */
typedef struct s_square_data
{
    int scale;            // Échelle du carré
    int offset_x;         // Décalage X
    int offset_y;         // Décalage Y
    int map_x;            // Position X dans la grille
    int map_y;            // Position Y dans la grille
    int color;            // Couleur du carré
} t_square_data;

typedef struct s_draw_player_data
{
    int size;             // Taille du marqueur du joueur
    double angle;         // Angle de rotation
    int arrow_x[3];       // Coordonnées X pour dessiner une flèche
    int arrow_y[3];       // Coordonnées Y pour dessiner une flèche
    t_player *player;     // Référence au joueur
} t_draw_player_data;

//utils
void			print_error(char *error);
void			print_error_arg(char *error, char *arg);
void 			free_2d_array(char **array, int height);
double	        get_time(void);
int             create_trgb(int t, int r, int g, int b);



/* ---------------------- */
/* ------ PARSING ------- */
/* ---------------------- */

// parse map 
int 			parse_map(char *mapfile, t_map_data *map_data);

// file validation.c
int				is_cub_file(char *file);

// file_parsing_1.c
t_map_config	*file_parsing(char *file);
int				config_map(int fd, t_map_config *map_config);
int				dispatch_line(char *line, t_map_config *map_config);
int				config_map_elements(char *line, t_map_config *map_config);
int				test_map_creation(char *line, t_map_config *map_config);

// file_parsing_2.c
int				only_spaces_in_line(char *line);

// map_config_utils.c
t_map_config	*init_map_config(void);
void			free_map(char **map);
void			delete_map_config(t_map_config *map_config);

// test_map_utils.c
int				add_test_map_node(char *line, t_map_config *map_config);
void			delete_test_map(t_test_map_node *test_map);

// map_config_elements_paths.c 
int				config_no_path(char *line, t_map_config *map_config);
int				config_so_path(char *line, t_map_config *map_config);
int				config_we_path(char *line, t_map_config *map_config);
int				config_ea_path(char *line, t_map_config *map_config);

// map_config_colors_1.c
int				config_f_color(char *line, t_map_config *map_config);
int				config_c_color(char *line, t_map_config *map_config);

// map_config_colors_2.c
int				split_color_line(char *line, t_map_config *map_config,
					char *color);

// map_config_validation.c
int				config_map_validation(t_map_config *map_config);
int				is_complete_config(t_map_config *map_config);
int				game_map_creation(t_map_config *map_config);
int				start_char_nb_validation(t_map_config *map_config);
int				create_game_map(t_map_config *map_config);

// game_map_utils_1.c
void			get_game_map_size(t_map_config *map_config);
int				fill_game_map(t_map_config *map_config);
int				get_start_position(t_map_config *map_config);
int				start_char_inside_walls(t_map_config *map_config);
void			transform_spaces_to_walls(t_map_config *map_config);

// game_map_utils_2.c
int				is_walled_map(t_map_config *map_config);
void			transform_spaces_to_void(t_map_config *map_config);
int				recursively_check_walls(char **map, int y, int x,
					int size[2]);
int				is_map_with_adjacent_walls(t_map_config *map_config);
int				recursively_check_adjacent_walls(char **map, int y, int x,
					int size[2]);

// game_map_utils_3.c
int				check_first_line(t_map_config *map_config);
int				check_middle_lines(t_map_config *map_config);
int				check_last_line(t_map_config *map_config);
int				is_closed_map(t_map_config *map_config);

/**** DEV ****/
void			display_map_config(t_map_config *map_config);
void			debug_print_map(t_map_config *map_config);



// cleanup fonctions
void 			clean_map_data(t_map_data *map, void *mlx);
void 			cleanup_game(t_game *game);


int 			check_args(char *mapfile, int argc);
t_map_data      *init_map(void);


#endif