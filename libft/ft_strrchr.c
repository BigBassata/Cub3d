/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:02:07 by julombar          #+#    #+#             */
/*   Updated: 2024/06/13 16:14:48 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		s_len;

	s_len = 0;
	while (s[s_len] != '\0')
		s_len++;
	i = s_len;
	while (i > -1)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	if ((char)c == '\0')
		return ((char *)&s[s_len]);
	return (NULL);
}
/*
int	main(void)
{
	char	str[] = "It's a long time";
	char	l = 'l';
	char	b = 'b';
	char	end = '\0';

	printf("strrchr(str, l): %s\n", strrchr(str, l));
	printf("strrchr(str, b): %s\n", strrchr(str, b));
	printf("strrchr(str, end): %s\n\n", strrchr(str, end));

	printf("ft_strrchr(str, l): %s\n", ft_strrchr(str, l));
	printf("ft_strrchr(str, b): %s\n", ft_strrchr(str, b));
	printf("ft_strrchr(str, end): %s\n", ft_strrchr(str, end));
	return (0);
}
*/
