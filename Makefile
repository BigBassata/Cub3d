# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile.c                                         :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2025/02/26 16:12:04 by julombar          #+#    #+#             #
#   Updated: 2025/02/26 16:45:17 by julombar         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME = cub3d
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MINI_LIBX_DIR = ./minilibx-linux
MINI_LIBX = $(MINI_LIBX_DIR)/libmlx.a

##### COMPILATEUR ET FLAGS #####
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

##### RÉPERTOIRES #####
SRC_DIR = srcs/
OBJ_DIR = obj/
INCLUDES_DIR = includes/

##### TESTS #####
TESTS_NAME = unit_tests
TESTS_DIR = tests/
TESTS_OBJ_DIR = $(OBJ_DIR)tests/
UNITY_DIR = ./Unity/
UNITY_SRC = $(UNITY_DIR)src/unity.c

##### SOURCES PRINCIPALES #####
SRC_FILES = main.c init.c \
	parsing/file_validation.c parsing/map_config_utils.c parsing/test_map_utils.c \
	parsing/file_parsing_1.c parsing/file_parsing_2.c parsing/map_config_elements_paths.c \
	parsing/map_config_validation.c parsing/game_map_utils_1.c parsing/game_map_utils_2.c \
	parsing/game_map_utils_3.c parsing/map_config_colors_1.c parsing/map_config_colors_2.c \
	parsing/parse_map.c utils/utils.c utils/colors_utils.c cleanup/ft_cleanup.c window/window_init.c

##### SOURCES DE TESTS #####
TESTS_SRC_FILES = main_test.c \
	parsing_test/parsing_test.c
# wall_textures/wall_textures_test.c #
# game_test/game_test.c #

##### CHEMINS COMPLETS #####
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))
TESTS_SRCS = $(addprefix $(TESTS_DIR), $(TESTS_SRC_FILES))
TESTS_OBJS = $(patsubst $(TESTS_DIR)%.c, $(TESTS_OBJ_DIR)%.o, $(TESTS_SRCS))

##### INCLUDES #####
INCLUDES = -I$(INCLUDES_DIR) -I$(LIBFT_DIR) -I$(MINI_LIBX_DIR)
TESTS_INCLUDES = $(INCLUDES) -I$(UNITY_DIR)src

##### SOUS-RÉPERTOIRES D'OBJETS #####
OBJ_SUBDIRS = $(OBJ_DIR)parsing $(OBJ_DIR)utils $(OBJ_DIR)cleanup $(OBJ_DIR)window
TESTS_OBJ_SUBDIRS = $(TESTS_OBJ_DIR)parsing_test
#$(TESTS_OBJ_DIR)wall_textures #
#$(TESTS_OBJ_DIR)game_test#

##### COULEURS #####
GREEN = \033[0;32m
BLUE = \033[0;34m
WHITE = \033[0;37m

##### RÈGLES #####
all: makedirs $(NAME)

makedirs: $(OBJ_DIR) $(OBJ_SUBDIRS)

$(OBJ_DIR) $(OBJ_SUBDIRS):
	@mkdir -p $@

$(MINI_LIBX):
	@echo "$(BLUE)Compilation de la MiniLibX...$(WHITE)"
	$(MAKE) -C $(MINI_LIBX_DIR)
	@echo "$(GREEN)MiniLibX compilée !$(WHITE)"

$(LIBFT):
	@echo "$(BLUE)Compilation de la Libft...$(WHITE)"
	$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft compilée !$(WHITE)"

$(NAME): $(OBJS) $(LIBFT) $(MINI_LIBX)
	@echo "$(BLUE)Compilation de $(NAME)...$(WHITE)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(MINI_LIBX_DIR) -lmlx -lX11 -lXext
	@echo "$(GREEN)$(NAME) compilé !$(WHITE)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

##### RÈGLES DE TEST #####
test: test_dirs $(TESTS_NAME)
	@echo "$(BLUE)Exécution des tests...$(WHITE)"
	./$(TESTS_NAME)
	@echo "$(GREEN)Tests terminés !$(WHITE)"

test_dirs: $(TESTS_OBJ_DIR) $(TESTS_OBJ_SUBDIRS)

$(TESTS_OBJ_DIR) $(TESTS_OBJ_SUBDIRS):
	@mkdir -p $@
$(TESTS_NAME): $(TESTS_OBJS) $(MINI_LIBX) $(filter-out $(OBJ_DIR)main.o, $(OBJS)) $(UNITY_SRC) $(LIBFT)
	@echo "$(BLUE)Compilation des tests unitaires...$(WHITE)"
	$(CC) $(CFLAGS) $(TESTS_INCLUDES) $(TESTS_OBJS) $(filter-out $(OBJ_DIR)main.o, $(OBJS)) $(UNITY_SRC) -o $(TESTS_NAME) -L$(LIBFT_DIR) -lft -L$(MINI_LIBX_DIR) -lmlx -lX11 -lXext -DTEST_MODE
	@echo "$(GREEN)Tests compilés !$(WHITE)"
	
$(TESTS_OBJ_DIR)%.o: $(TESTS_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(TESTS_INCLUDES) -c $< -o $@

##### NETTOYAGE #####
clean:
	@echo "$(BLUE)Suppression des fichiers objets...$(WHITE)"
	@rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINI_LIBX_DIR) clean
	@echo "$(GREEN)Fichiers objets supprimés !$(WHITE)"

fclean: clean
	@echo "$(BLUE)Suppression de $(NAME) et $(TESTS_NAME)...$(WHITE)"
	@rm -f $(NAME)
	@rm -f $(TESTS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Exécutables supprimés !$(WHITE)"

re: fclean all

.PHONY: all clean fclean re makedirs test test_dirs


# NAME = cub3d
# LIBFT_DIR = libft
# LIBFT = $(LIBFT_DIR)/libft.a
# MINI_LIBX_DIR = ./minilibx-linux
# MINI_LIBX = $(MINI_LIBX_DIR)/libmlx.a

# ##### COMPILATEUR ET FLAGS #####
# CC = cc
# CFLAGS = -Wall -Wextra -Werror -g3

# ##### RÉPERTOIRES #####
# SRC_DIR = srcs/
# OBJ_DIR = obj/
# INCLUDES_DIR = includes/

# ##### TESTS #####
# TESTS_NAME = unit_tests
# TESTS_DIR = tests/
# TESTS_OBJ_DIR = $(OBJ_DIR)tests/
# UNITY_DIR = $(TESTS_DIR)Unity/
# UNITY_SRC = $(UNITY_DIR)src/unity.c

# ##### SOURCES PRINCIPALES #####
# SRC_FILES = main.c \
# 	parsing/file_validation.c parsing/map_config_utils.c parsing/test_map_utils.c \
# 	parsing/file_parsing_1.c parsing/file_parsing_2.c parsing/map_config_elements_paths.c \
# 	parsing/map_config_validation.c parsing/game_map_utils_1.c parsing/game_map_utils_2.c \
# 	parsing/game_map_utils_3.c parsing/map_config_colors_1.c parsing/map_config_colors_2.c \
# 	parsing/parse_map.c utils/utils.c utils/colors_utils.c cleanup/ft_cleanup.c window/window_init.c

# ##### SOURCES DE TESTS #####
# TESTS_SRC_FILES = main_test.c \
# 	parsing_test/parsing_test.c 
# # wall_textures/wall_textures_test.c #
# # game_test/game_test.c #

# ##### CHEMINS COMPLETS #####
# SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
# OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))
# TESTS_SRCS = $(addprefix $(TESTS_DIR), $(TESTS_SRC_FILES))
# TESTS_OBJS = $(patsubst $(TESTS_DIR)%.c, $(TESTS_OBJ_DIR)%.o, $(TESTS_SRCS))

# ##### INCLUDES #####
# INCLUDES = -I$(INCLUDES_DIR) -I$(LIBFT_DIR) -I$(MINI_LIBX_DIR)
# TESTS_INCLUDES = $(INCLUDES) -I$(UNITY_DIR)src

# ##### SOUS-RÉPERTOIRES D'OBJETS #####
# OBJ_SUBDIRS = $(OBJ_DIR)parsing $(OBJ_DIR)utils $(OBJ_DIR)cleanup $(OBJ_DIR)window
# TESTS_OBJ_SUBDIRS = $(TESTS_OBJ_DIR)parsing_test 
# #$(TESTS_OBJ_DIR)wall_textures #
# #$(TESTS_OBJ_DIR)game_test#
# ##### COULEURS #####
# GREEN = \033[0;32m
# BLUE = \033[0;34m
# WHITE = \033[0;37m

# ##### RÈGLES #####
# all: makedirs $(NAME)

# makedirs: $(OBJ_DIR) $(OBJ_SUBDIRS)

# $(OBJ_DIR) $(OBJ_SUBDIRS):
# 	@mkdir -p $@

# $(MINI_LIBX):
# 	@echo "$(BLUE)Compilation de la MiniLibX...$(WHITE)"
# 	$(MAKE) -C $(MINI_LIBX_DIR)
# 	@echo "$(GREEN)MiniLibX compilée !$(WHITE)"

# $(LIBFT):
# 	@echo "$(BLUE)Compilation de la Libft...$(WHITE)"
# 	$(MAKE) -C $(LIBFT_DIR)
# 	@echo "$(GREEN)Libft compilée !$(WHITE)"

# $(NAME): $(OBJS) $(LIBFT) $(MINI_LIBX)
# 	@echo "$(BLUE)Compilation de $(NAME)...$(WHITE)"
# 	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(MINI_LIBX_DIR) -lmlx -lX11 -lXext
# 	@echo "$(GREEN)$(NAME) compilé !$(WHITE)"

# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ##### RÈGLES DE TEST #####
# test: test_dirs $(TESTS_NAME)
# 	@echo "$(BLUE)Exécution des tests...$(WHITE)"
# 	./$(TESTS_NAME)
# 	@echo "$(GREEN)Tests terminés !$(WHITE)"

# test_dirs: $(TESTS_OBJ_DIR) $(TESTS_OBJ_SUBDIRS)

# $(TESTS_OBJ_DIR) $(TESTS_OBJ_SUBDIRS):
# 	@mkdir -p $@

# $(TESTS_NAME): $(filter-out $(OBJ_DIR)srcs/main.o, $(OBJS)) $(TESTS_OBJS) $(UNITY_SRC) $(LIBFT) $(MINI_LIBX)
# 	@echo "$(BLUE)Compilation des tests unitaires...$(WHITE)"
# 	$(CC) $(CFLAGS) $(TESTS_INCLUDES) $^ -o $(TESTS_NAME) -L$(LIBFT_DIR) -lft -L$(MINI_LIBX_DIR) -lmlx -lX11 -lXext
# 	@echo "$(GREEN)Tests compilés !$(WHITE)"

# $(TESTS_OBJ_DIR)%.o: $(TESTS_DIR)%.c
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) $(TESTS_INCLUDES) -c $< -o $@

# ##### NETTOYAGE #####
# clean:
# 	@echo "$(BLUE)Suppression des fichiers objets...$(WHITE)"
# 	@rm -rf $(OBJ_DIR)
# 	$(MAKE) -C $(LIBFT_DIR) clean
# 	$(MAKE) -C $(MINI_LIBX_DIR) clean
# 	@echo "$(GREEN)Fichiers objets supprimés !$(WHITE)"

# fclean: clean
# 	@echo "$(BLUE)Suppression de $(NAME) et $(TESTS_NAME)...$(WHITE)"
# 	@rm -f $(NAME)
# 	@rm -f $(TESTS_NAME)
# 	$(MAKE) -C $(LIBFT_DIR) fclean
# 	@echo "$(GREEN)Exécutables supprimés !$(WHITE)"

# re: fclean all

# .PHONY: all clean fclean re makedirs test test_dirs


# NAME = cub3d
# LIBFT_DIR = libft
# LIBFT = $(LIBFT_DIR)/libft.a
# MINI_LIBX_DIR = ./minilibx-linux
# MINI_LIBX = $(MINI_LIBX_DIR)/libmlx.a

# CC = cc
# CFLAGS = -Wall -Wextra -Werror -g3
# INCLUDES = -I./includes -I$(LIBFT_DIR) -I$(MINI_LIBX_DIR)

# SRC_DIR = srcs/
# OBJ_DIR = obj/

# SRC_FILES = main.c \
# 	parsing/file_validation.c parsing/map_config_utils.c parsing/test_map_utils.c parsing/file_parsing_1.c \
# 	parsing/file_parsing_2.c parsing/map_config_elements_paths.c parsing/map_config_validation.c \
# 	parsing/game_map_utils_1.c parsing/game_map_utils_2.c parsing/game_map_utils_3.c parsing/map_config_colors_1.c parsing/map_config_colors_2.c \
# 	parsing/parse_map.c utils/utils.c utils/colors_utils.c cleanup/ft_cleanup.c window/window_init.c

# SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

# OBJ_SUBDIRS = $(OBJ_DIR)parsing $(OBJ_DIR)utils $(OBJ_DIR)cleanup $(OBJ_DIR)window

# OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

# all: makedirs $(NAME)

# makedirs: $(OBJ_DIR) $(OBJ_SUBDIRS)

# $(OBJ_DIR) $(OBJ_SUBDIRS):
# 	@mkdir -p $@

# $(MINI_LIBX):
# 	$(MAKE) -C $(MINI_LIBX_DIR)

# $(LIBFT):
# 	$(MAKE) -C $(LIBFT_DIR)

# $(NAME): $(OBJS) $(LIBFT) $(MINI_LIBX)
# 	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(MINI_LIBX_DIR) -lmlx -lX11 -lXext

# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# clean:
# 	rm -rf $(OBJ_DIR)
# 	$(MAKE) -C $(LIBFT_DIR) clean
# 	$(MAKE) -C $(MINI_LIBX_DIR) clean

# fclean: clean
# 	rm -f $(NAME)
# 	$(MAKE) -C $(LIBFT_DIR) fclean
# 	$(MAKE) -C $(MINI_LIBX_DIR) clean

# re: fclean all

# .PHONY: all clean fclean re makedirs