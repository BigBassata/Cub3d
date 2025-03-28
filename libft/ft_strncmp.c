/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:29:53 by julombar          #+#    #+#             */
/*   Updated: 2024/06/13 19:20:49 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t			i;
	unsigned char	*s1_temp;
	unsigned char	*s2_temp;

	i = 0;
	s1_temp = (unsigned char *)s1;
	s2_temp = (unsigned char *)s2;
	while (i < size)
	{
		if (s1_temp[i] != s2_temp[i]
			|| s1_temp[i] == '\0' || s2_temp[i] == '\0')
			return ((int)s1_temp[i] - s2_temp[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str1[] = "Just do it";
	char	str2[] = "Just a test";
	char	str3[] = "a test";
	size_t	size1 = 3;
	size_t	long_size1 = 3;
	size_t	zero_size1 = 0;

	printf("str1 vs str2: %i\n", strncmp(str1, str2, size1));
	printf("str1 vs str: %i\n", strncmp(str1, str3, size1));
	printf("str1 vs str2 - long_size: %i\n", strncmp(str1, str2, long_size1));
	printf("str1 vs str2 - zero_size: %i\n", strncmp(str1, str2, zero_size1));

	printf("\n");

	printf("str1 vs str2: %i\n", ft_strncmp(str1, str2, size1));
	printf("str1 vs str: %i\n", ft_strncmp(str1, str3, size1));
	printf("str1 vs str2 - long_size: %i\n", ft_strncmp(str1, str2, long_size1));
	printf("str1 vs str2 - zero_size: %i\n", ft_strncmp(str1, str2, zero_size1));

	return (0);
}
*/
