/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:29:46 by julombar          #+#    #+#             */
/*   Updated: 2024/06/13 21:07:36 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		s_len;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	s_len = 0;
	while (s[s_len] != '\0')
		s_len++;
	str = (char *)malloc(s_len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char	test_func(unsigned int i, char c)
{
	return (c + i);
}

int	main(void)
{
	char	*str1 = "1234567";

	char	*test1 = ft_strmapi(str1, test_func);

	printf("\nstr1: %s\n", str1);
	printf("test1: %s\n\n", test1);

	if (test1 != NULL)
		free(test1);

	return (0);
}
*/
