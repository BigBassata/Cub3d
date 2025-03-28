/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:12:04 by julombar          #+#    #+#             */
/*   Updated: 2024/06/13 19:44:08 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_spaces(const char *nptr, int i)
{
	while (nptr[i] != '\0')
	{
		if (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
			|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
			i++;
		else
			break ;
	}
	return (i);
}

static int	handle_compute(const char *nptr, int index,
	long int result, int sign)
{
	while (nptr[index] != '\0')
	{
		if (nptr[index] >= '0' && nptr[index] <= '9')
			result = (result + nptr[index] - '0') * 10;
		else
			break ;
		index++;
	}
	if (sign == 0)
		sign = 1;
	if (result == -2147483648)
		return (-2147483648);
	return ((result / 10) * sign);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 0;
	result = 0;
	i = handle_spaces(nptr, i);
	while (nptr[i] != '\0')
	{
		if (nptr[i] == '-' && sign == 0)
			sign = -1;
		else if (nptr[i] == '+' && sign == 0)
			sign = 1;
		else if (nptr[i] >= '0' && nptr[i] <= '9')
			break ;
		else
			return (0);
		i++;
	}
	return (handle_compute(nptr, i, result, sign));
}
/*
int	main(int argc, char **argv)
{
	//char	test1[] = " ---+--+1234ab567";
	//int	result1 = ft_atoi(test1);
	//int	result2 = atoi(test1);
	if (argc > 1)
	{
		printf("\nft_atoi arg: %i\n", ft_atoi(argv[1]));
		printf("atoi arg: %i\n\n", atoi(argv[1]));
	}
	//printf("result1 ft_atoi: %i\n", result1);
	//printf("result2 atoi: %i\n\n", result2);
	return (0);
}
*/
