/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 23:19:22 by julombar          #+#    #+#             */
/*   Updated: 2024/06/13 20:51:15 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*malloc_one(void)
{
	char	*arr;

	arr = (char *)malloc(1);
	if (arr == NULL)
		return (NULL);
	arr[0] = '\0';
	return (arr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*arr;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = 0;
	while (s[s_len] != '\0')
		s_len++;
	if (start >= s_len)
		return (arr = malloc_one());
	if (start + len > s_len)
		len = s_len - start;
	arr = (char *)malloc(len + 1);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		arr[i] = s[start + i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
/*
int	main(void)
{
	char	*str1 = "Une chaine de char!";
	char	*sub1 = ft_substr(str1, 4, 6);
	printf("\nstr1: %s\n", str1);
	printf("sub1: %s\n\n", sub1);
	if (sub1 != NULL)
		free(sub1);
	return (0);
}
*/
