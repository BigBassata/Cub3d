/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2025/02/26 18:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *error)
{
	ft_putstr_fd("Error: ", 2);
	if (error)
		ft_putstr_fd(error, 2);
	ft_putendl_fd("", 2);
}

void	print_error_arg(char *error, char *arg)
{
	ft_putstr_fd("Error: ", 2);
	if (error)
		ft_putstr_fd(error, 2);
	if (arg)
		ft_putstr_fd(error, 2);
	ft_putendl_fd("", 2);
}
