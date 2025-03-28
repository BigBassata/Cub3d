/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:17:01 by julombar          #+#    #+#             */
/*   Updated: 2024/06/10 15:49:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_dest;

	if (dest == NULL && src == NULL && n != 0)
		return (NULL);
	i = 0;
	temp_dest = dest;
	while (i < n)
	{
		temp_dest[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
   char	str[50] = "Just a test!";
   char	str_dest[50];
   char	str2[50] = "Just a test!";
   char	str_dest2[50];

   int	arr[] = { 1, 2, 3, 4, 5};
   int	arr_dest[5] = { 0, 0, 0, 0, 0};
   int	arr2[] = { 1, 2, 3, 4, 5};
   int	arr_dest2[5] = { 0, 0, 0, 0, 0};

   memcpy(str_dest, str, 4);
   printf("str_dest: %s\n", str_dest);

   ft_memcpy(str_dest2, str2, 4);
   printf("str_dest2: %s\n", str_dest2);

   //memcpy(NULL, NULL, 3);
   //ft_memcpy(NULL, NULL, 3);

   memcpy(arr_dest, arr, 8);
   for (int i = 0; i < 5; i++)
   {
   printf("arr_dest[%i]: %d\n", i,  arr_dest[i]);
   printf("sizeof(arr[%i]): %lu\n", i,  sizeof(arr[i]));
   }
   printf("\n");

   ft_memcpy(arr_dest2, arr2, 8);
   for (int i = 0; i < 5; i++)
   {
   printf("arr_dest2[%i]: %d\n", i, arr_dest2[i]);
   printf("sizeof(arr2[%i]): %lu\n", i,  sizeof(arr2[i]));
   }
   printf("\n");

   return (0);
}
*/
