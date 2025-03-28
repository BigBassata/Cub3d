/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:39:07 by julombar          #+#    #+#             */
/*   Updated: 2024/06/13 19:05:11 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	i = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 1)
		dst[0] = '\0';
	else if (size > 1)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
/*
int	main (void)
{
	char	str[] = "Just a test";
	char	str2[12];
	char	str3[1];
	char	str4[1];
	char	str5[10];

	printf("ft_strlcpy: %zu\n", ft_strlcpy(str2, str, 12));
	printf("str2: %s\n\n", str2);

	printf("ft_strlcpy(str3, str, 0): %zu\n", ft_strlcpy(str3, str, 0));
	printf("str3[1]: %s\n\n", str3);

	printf("ft_strlcpy(str4, str, 1): %zu\n", ft_strlcpy(str4, str, 1));
	printf("str4[1]: %s\n\n", str4);

	printf("ft_strlcpy(str5, str, 10): %zu\n", ft_strlcpy(str5, str, 10));
	printf("str5[10]: %s\n\n", str5);
	return (0);
}
*/
