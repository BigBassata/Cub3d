/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:08:18 by julombar          #+#    #+#             */
/*   Updated: 2024/06/13 19:20:54 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_temp;
	unsigned char	c_temp;

	i = 0;
	s_temp = (unsigned char *)s;
	c_temp = (unsigned char)c;
	while (i < n)
	{
		if (s_temp[i] == c_temp)
			return (&s_temp[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	str1[] = "Just another test";
	char	a = 'a';
	char	b = 'b';
	size_t	size1 = 10;
	size_t	long_size1 = 30;

	int	arr1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int arr2[7] = {-49, 49, 1, -1, 0, -2, 2};
	int	five = 5;
	int	nine = 9;
	size_t	arr_size1 = 36;

	printf("memchr(str1, a, size1): %s\n", 
		(char *)memchr(str1, a, size1));
	printf("memchr(str1, b, size1): %s\n", 
		(char *)memchr(str1, b, size1));
	printf("memchr(str1, a, long_size1): %s\n",
		(char *)memchr(str1, b, long_size1));

	printf("memchr(arr1, five, arr_size1): %p\n",
		memchr(arr1, five, arr_size1));
	printf("memchr(arr1, five, arr_size1): %p\n",
		memchr(arr1, nine, arr_size1));
	
	printf("memchr(arr2, -1, 7 * sizeof(int): %p\n",
		memchr(arr2, -1, 7));

	printf("\n");

	printf("ft_memchr(str1, a, size1): %s\n",
		(char *)ft_memchr(str1, a, size1));
	printf("ft_memchr(str1, b, size1): %s\n",
		(char *)ft_memchr(str1, b, size1));
	printf("ft_memchr(str1, a, long_size1): %s\n",
		(char *)ft_memchr(str1, b, long_size1));

	printf("ft_memchr(arr1, five, arr_size1): %p\n",
		ft_memchr(arr1, five, arr_size1));
	printf("ft_memchr(arr1, five, arr_size1): %p\n",
		ft_memchr(arr1, nine, arr_size1));

	printf("ft_memchr(arr2, -1, 7 * sizeof(int)): %p\n",
		ft_memchr(arr2, -1, 7));

	return (0);
}
*/
