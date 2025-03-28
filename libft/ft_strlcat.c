/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:39:07 by julombar          #+#    #+#             */
/*   Updated: 2024/06/13 19:03:12 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] != '\0')
		dst_len++;
	while (src[src_len] != '\0')
		src_len++;
	i = dst_len;
	j = 0;
	if (size < dst_len || size == 0)
		return (size + src_len);
	while (i < size - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
/*
int	main(void)
{
	char	str1[50] = "Just a test";
	char	str2[12] = ", again";
	char	str3[50] = "Just a test";
	size_t	str_size = 50;
	size_t	str3_inf_size = 5;

	printf("ft_strlcat: %zu\n", ft_strlcat(str1, str2, str_size));
	printf("str1: %s\n\n", str1);

	printf("ft_strlcat: %zu\n", ft_strlcat(str3, str2, str3_inf_size));
	printf("str3: %s\n\n", str3);

	return (0);
}
*/
