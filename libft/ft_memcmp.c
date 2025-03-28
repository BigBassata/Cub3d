/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:40:47 by julombar          #+#    #+#             */
/*   Updated: 2024/06/13 19:21:05 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_temp;
	unsigned char	*s2_temp;

	i = 0;
	s1_temp = (unsigned char *)s1;
	s2_temp = (unsigned char *)s2;
	while (i < n)
	{
		if (s1_temp[i] != s2_temp[i])
			return ((int)s1_temp[i] - s2_temp[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str1[] = "Just another test";
	char	str2[] = "Just an illusion";
	size_t	size1 = 8;

	int	arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	arr2[] = {0, 1, 2, 3, 4, 0, 0, 0, 0, 0};
	size_t	size2 = 36;


	//printf("memcmp(str1, str2, size1): %i\n", memcmp(str1, str2, size1));
	//printf("memcmp(arr1, arr2, size2): %i\n", memcmp(arr1, arr2, size2));
	
	//printf("\n");
	
	printf("ft_memcmp(str1, str2, size1): %i\n", ft_memcmp(str1, str2, size1));
	printf("ft_memcmp(arr1, arr2, size2): %i\n", ft_memcmp(arr1, arr2, size2));

	return (0);
}
*/
