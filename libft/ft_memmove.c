/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2024/06/10 19:49:18 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	if (dest == NULL && src == NULL && n != 0)
		return (NULL);
	i = 0;
	temp_dest = dest;
	temp_src = (unsigned char *)src;
	if (temp_dest < temp_src)
	{
		while (i < n)
		{
			temp_dest[i] = ((unsigned char *)temp_src)[i];
			i++;
		}
		return (dest);
	}
	while (i < n)
	{
		temp_dest[n - i - 1] = ((unsigned char *)temp_src)[n - i - 1];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	str[50] = "Just a test!";
	char	str2[50] = "Just a test!";
	char	str3[] = "memmove can be very useful......";
	char	str4[] = "memmove can be very useful......";
	char	str5[] = "lorem ipssum dolor sit amet";
	char	str6[] = "lorem ipssum dolor sit amet";
	char	*dest5 = str5 + 1;
	char	*dest6 = str6 + 1;
//	int	arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	int	arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	char	str7[50] = "Just a test!";
	char	str8[50] = "Just a test!";

	printf("\n");
	memmove(str + 7, str, 4);
	printf("str: %s\n", str);

	ft_memmove(str2 + 7, str2, 4);
	printf("str2: %s\n", str2);

	memmove(str3 + 20, str3 + 15, 11);
	printf("str3: %s\n", str3);
	
	ft_memmove(str4 + 20, str4 + 15, 11);
	printf("str4: %s\n", str4);



	printf("\nstr6 + 1: %s\n", str6 + 1);
	printf("\ndest5 bef: %s\n", dest5);
	memmove(str5, dest5, 8);
	printf("dest5 aft: %s\n", dest5);

	printf("dest6 bef: %s\n", dest6);
	ft_memmove(str6, dest6, 8);
	printf("dest6 aft: %s\n\n", dest6);



	memmove(str7, str7 +7, 4);
	printf("str7: %s\n", str7);

	ft_memmove(str8, str8 + 7, 4);
	printf("str8: %s\n", str8);


	printf("\n");
	memmove(arr + 5, arr, 20);
	printf("arr: ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ",  arr[i]);
	}
	printf("\n");

	ft_memmove(arr2 + 5, arr2, 20);
	printf("arr2: ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");

	return (0);
}
*/
