/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:59:53 by julombar          #+#    #+#             */
/*   Updated: 2024/06/13 19:36:56 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;
	size_t	j;

	little_len = 0;
	while (little[little_len] != '\0')
		little_len++;
	if (little_len == 0)
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] != '\0' && i + j < len)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	big1[] = "Just another test again";

	char	little1[] = "Just";
	size_t	size1 = 6;

	char	little2[] = "test";
	char	little3[] = "again";
	char	little4[] = "nothing";
	size_t	size2 = 23;
	size_t	size3 = 0;

	printf("Just: %s\n" ,strnstr(big1, little1, size1));
		printf("\n");
	printf("test: %s\n" ,strnstr(big1, little2, size2));
		printf("\n");
	printf("again: %s\n" ,strnstr(big1, little3, size2));
		printf("\n");
	printf("Null: %s\n" ,strnstr(big1, little1, size3));
		printf("\n");
	printf("Null: %s\n" ,strnstr(big1, little4, size2));

	return (0);
}
*/
