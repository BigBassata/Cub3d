/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:05:10 by julombar          #+#    #+#             */
/*   Updated: 2024/06/13 21:08:25 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	test_func(unsigned int i, char *c)
{
	*c = *c + i;
}

int	main(void)
{
	char	str1[] = "AAAAAAAAAA";

	printf("\nstr1 before: %s\n", str1);
	ft_striteri(str1, test_func);
	printf("str1 after: %s\n\n", str1);

	return (0);
}
*/
