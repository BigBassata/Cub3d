/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:02:07 by julombar          #+#    #+#             */
/*   Updated: 2024/06/13 16:12:45 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*
int	main(void)
{
	char	str[] = "It's a long time";
	char	l = 'l';
	char	b = 'b';
	char	end = '\0';
	char	*src = "īœ˙ˀ˘¯ˇ¸¯.œ«‘––™ª•¡¶¢˜ˀ";

	printf("strchr(str, l): %s\n", strchr(str, l));
	printf("strchr(str, b): %s\n", strchr(str, b));
	printf("strchr(str, b): %s\n\n", strchr(str, end));
	printf("strchr(src, L'–'): %s\n\n", strchr(src, L'–'));
	printf("strchr(Tripuille, t + 256): %s\n\n",
	strchr("Tripouille", 't' + 256));

	printf("ft_strchr(str, l): %s\n", ft_strchr(str, l));
	printf("ft_strchr(str, b): %s\n", ft_strchr(str, b));
	printf("ft_strchr(str, b): %s\n", ft_strchr(str, end));
	printf("ft_strchr(src, L'–'): %s\n", ft_strchr(src, L'–'));
	printf("ft_strchr(Tripuille, t + 256): %s\n\n",
	ft_strchr("Tripouille", 't' + 256));
	return (0);
}
*/
