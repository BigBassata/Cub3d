/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2024/06/13 18:29:09 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = s;
	while (i < n)
	{
		temp[i] = c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char	str[50] = "Just a test!";
	char	str2[50] = "Just a test!";
	int	arr[] = { 1, 2, 3, 4, 5};
	int	arr2[] = { 1, 2, 3, 4, 5};

	printf("str before: %s\n", str);
	memset(str, 'A', 5);
	printf("str after: %s\n", str);
	printf("\n");

	printf("str2 before: %s\n", str2);
	ft_memset(&str2, 'A', 5);
	printf("str2 after: %s\n", str2);
	
	printf("\n");
	printf("arr before:\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
		printf("sizeof(arr[%i]): %lu - int = %i \n", i, sizeof(arr[i]), arr[i]);
	}
	memset(arr, 0, 20);
	printf("\n");
	printf("arr after:\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
		printf("sizeof(arr[%i]): %lu - int = %i \n", i, sizeof(arr[i]), arr[i]);
	}
	printf("\n");
	printf("==================\n");
	printf("\n");


	printf("\n");
	printf("arr2 before:\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr2[i]);
		printf("sizeof(arr2[%i]): %lu - int = %i \n", i, sizeof(arr2[i]), arr2[i]);
	}
	printf("\n");
	ft_memset(&arr2, 0, 20);
	printf("\n");
	printf("arr2 after:\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr2[i]);
		printf("sizeof(arr2[%i]): %lu - int = %i \n", i, sizeof(arr2[i]), arr2[i]);
	}
	printf("\n");

	return (0);
}
*/
