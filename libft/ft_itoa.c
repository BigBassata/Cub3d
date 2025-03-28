/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:42:37 by julombar          #+#    #+#             */
/*   Updated: 2024/06/13 21:16:24 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*handle_intmin(void)
{
	char	*str;
	char	*intmin;
	int		i;

	str = (char *)malloc(11 + 1);
	if (str == NULL)
		return (NULL);
	intmin = "-2147483648";
	i = 0;
	while (intmin[i] != '\0')
	{
		str[i] = intmin[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	get_strlen(long int n, int neg)
{
	long int	n_temp;
	int			counter;

	n_temp = n;
	counter = 0;
	while (n_temp > 9)
	{
		n_temp /= 10;
		counter++;
	}	
	counter++;
	return (counter + neg);
}

static void	fill_str(char *str, long int n, int neg, int strlen)
{
	if (neg == 1)
		str[0] = '-';
	str[strlen] = '\0';
	strlen--;
	while (n >= 10)
	{
		str[strlen] = n % 10 + '0';
		n /= 10;
		strlen--;
	}
	str[strlen] = n + '0';
}

char	*ft_itoa(int n)
{
	char		*str;
	int			neg;
	int			strlen;
	long int	n_temp;

	n_temp = n;
	if (n_temp == -2147483648)
		return (str = handle_intmin());
	neg = 0;
	if (n_temp < 0)
	{
		neg = 1;
		n_temp *= -1;
	}
	strlen = get_strlen(n_temp, neg);
	str = (char *)malloc(strlen + 1);
	if (str == NULL)
		return (NULL);
	fill_str(str, n_temp, neg, strlen);
	return (str);
}
/*
int	main(void)
{
	int		nb1 = 42;
	int		nb2 = -42;
	int		nb3 = 0;
	int		nb4 = 2147483647;
	int		nb5 = -2147483647;
	int		nb6 = -2147483648;
	char	*test1 = ft_itoa(nb1);
	char	*test2 = ft_itoa(nb2);
	char	*test3 = ft_itoa(nb3);
	char	*test4 = ft_itoa(nb4);
	char	*test5 = ft_itoa(nb5);
	char	*test6 = ft_itoa(nb6);

	printf("nb1: %s\n", test1);
	printf("nb2: %s\n", test2);
	printf("nb3: %s\n", test3);
	printf("nb4: %s\n", test4);
	printf("nb5: %s\n", test5);
	printf("nb6: %s\n", test6);

	if (test1 != NULL)
		free(test1);

	if (test2 != NULL)
		free(test2);

	if (test3 != NULL)
		free(test3);

	if (test4 != NULL)
		free(test4);

	if (test5 != NULL)
		free(test5);

	if (test6 != NULL)
		free(test6);

	return (0);
}
*/
