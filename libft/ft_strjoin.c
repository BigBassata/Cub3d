/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 23:49:59 by julombar          #+#    #+#             */
/*   Updated: 2024/06/14 17:48:34 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

static void	join_s2(char *arr, size_t i, char const *s2, size_t s2_len)
{
	size_t		j;

	j = 0;
	while (j < s2_len && s2[j] != '\0')
	{
		arr[i] = s2[j];
		i++;
		j++;
	}
	arr[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		s1_len;
	size_t		s2_len;
	char		*arr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	arr = (char *)malloc(s1_len + s2_len + 1);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len && s1[i] != '\0')
	{
		arr[i] = s1[i];
		i++;
	}
	join_s2(arr, i, s2, s2_len);
	return (arr);
}
/*
int	main(void)
{
	char	*str1 = "une chaine";
	char	*str2 = " de chars!";
	char	*str_join = ft_strjoin(str1, str2);
	printf("\nstr_join: %s\n", str_join);
	if (str_join != NULL)
		free(str_join);
	return (0);
}
*/
