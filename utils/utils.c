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

#include "../cub3d.h"


double	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((double)tv.tv_sec + (double)tv.tv_usec / 1000000.0);
}

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

void	free_2d_array(char **array, int height)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	if (height == -1)
	{
		while (array[i])
			free(array[i++]);
	}
	else
	{
		while (i < height)
		{
			if (array[i])
			{
				free(array[i]);
				array[i] = NULL;
			}
			i++;
		}
	}
	free(array);
}
