/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/02/26 18:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	add_test_map_node(char *line, t_map_config *map_config)
{
	t_test_map_node	*test_map_node;
	t_test_map_node	*tmp;

	test_map_node = malloc(sizeof(t_test_map_node));
	if (!test_map_node)
		return (print_error("malloc test_map_node"), ERROR);
	test_map_node->next = NULL;
	test_map_node->line = ft_strdup(line);
	if (!test_map_node->line)
		return (free(test_map_node),
			print_error("ft_strdup in add_test_map_node"), ERROR);
	if (!map_config->test_map)
		map_config->test_map = test_map_node;
	else
	{
		tmp = map_config->test_map;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = test_map_node;
	}
	return (TRUE);
}

void	delete_test_map(t_test_map_node *test_map)
{
	t_test_map_node	*tmp;

	while (test_map)
	{
		tmp = test_map;
		test_map = test_map->next;
		if (tmp->line)
			free(tmp->line);
		tmp->next = NULL;
		free(tmp);
	}
}
