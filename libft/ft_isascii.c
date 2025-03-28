/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:21:50 by julombar          #+#    #+#             */
/*   Updated: 2024/05/23 20:10:43 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
int	main(int argc, char *argv[])
{
	if (argc > 0)
	{
		printf("ft_isascii: %d \n", ft_isascii(argv[1][0]));
	}
	printf("ft_isascii() New Line: %d \n", ft_isascii('\n'));
	printf("ft_isascii() Null: %d \n", ft_isascii('\0'));
	return (0);
}
*/
