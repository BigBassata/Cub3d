/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2024/06/13 18:29:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = s;
	while (i < n)
	{
		temp[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	char	str[50] = "Just a test!";
	char	str2[50] = "Just a test!";
	int	arr[] = { 1, 2, 3, 4, 5};
	int	arr2[] = { 1, 2, 3, 4, 5};

	printf("str before: %s\n", str);
	bzero(str, 5);
	printf("str after: ");
	for (int i = 0; i < 12; i++)
	{
		printf("%c ", str[i]);
	}
	printf("\n");

	printf("str2 before: %s\n", str2);
	ft_bzero(str2, 5);
	printf("str2 after: ");
	for (int i = 0; i < 12; i++)
	{
		printf("%c ", str2[i]);
	}
	printf("\n");
	
	printf("\n");
	printf("arr before:\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
		printf("sizeof(arr[%i]): %lu - int = %i \n", i, sizeof(arr[i]), arr[i]);
	}
	bzero(arr, 20);
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
	ft_bzero(arr2, 20);
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
