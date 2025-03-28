/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:12:23 by julombar          #+#    #+#             */
/*   Updated: 2024/06/13 20:42:19 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	s_len;
	char	*arr;

	s_len = 0;
	while (s[s_len] != '\0')
		s_len++;
	arr = (char *)malloc(s_len + 1);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
/*
int	main(void)
{
	char	*str1 = "Une chaine de char!";
	char	*str1_dup = ft_strdup(str1);

	printf("\nstr1: %s\n", str1);
	printf("str1_dup: %s\n\n", str1_dup);

	if (str1_dup != NULL)
		free(str1_dup);
	return (0);
}
*/
