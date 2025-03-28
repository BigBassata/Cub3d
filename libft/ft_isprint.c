/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:21:50 by julombar          #+#    #+#             */
/*   Updated: 2024/06/10 14:14:05 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	else
		return (0);
}
/*
int	main(int argc, char *argv[])
{
	if (argc > 0)
		printf("ft_isprint: %d \n", ft_isprint(argv[1][0]));
	printf("ft_isprint('\n'): %d \n", ft_isprint('\n'));
	return (0);
}
*/
