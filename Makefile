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

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3


SRCS = main.c error.c \
	./parsing/file_validation.c ./parsing/map_config_utils.c ./parsing/test_map_utils.c ./parsing/file_parsing_1.c \
	./parsing/file_parsing_2.c ./parsing/map_config_elements_paths.c ./parsing/map_config_validation.c \
	./parsing/game_map_utils_1.c ./parsing/game_map_utils_2.c ./parsing/game_map_utils_3.c ./parsing/map_config_colors_1.c ./parsing/map_config_colors_2.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(MINI_LIBX):
	$(MAKE) -C $(MINI_LIBX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MINI_LIBX)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(MINI_LIBX_DIR) -lmlx -lX11 -lXext

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINI_LIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MINI_LIBX_DIR) clean

re: fclean all

.PHONY: all clean fclean re