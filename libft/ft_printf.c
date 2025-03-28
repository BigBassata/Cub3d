/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:08:02 by julombar          #+#    #+#             */
/*   Updated: 2024/10/08 16:38:54 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_format(const char *str, va_list args)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count += print_char(va_arg(args, int));
	else if (*str == 's')
		count += print_str(va_arg(args, char *));
	else if (*str == 'p')
		count += print_ptr(va_arg(args, void *));
	else if (*str == 'i' || *str == 'd')
		count += print_nbr(va_arg(args, int));
	else if (*str == 'u')
		count += print_u(va_arg(args, unsigned int));
	else if (*str == 'x')
		count += print_hexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (*str == 'X')
		count += print_hexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	return (count);
}

static int	match_format(const char *str)
{
	if (*str == 'c' || *str == 's' || *str == 'p'
		|| *str == 'i' || *str == 'd' || *str == 'u'
		|| *str == 'x' || *str == 'X')
		return (1);
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (match_format(str))
				count += check_format(str, args);
			else if (*str == '%')
				count += print_char('%');
		}
		else
			count += print_char(*str);
		str++;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	int ft1 = ft_printf("\nft1: s:%s, c:%c, percent:%%, i:%i, u:%u\n",
		(char *)NULL,
		0,
		INT32_MIN,
		-42);
	ft_printf("ft1 len: %d\n", ft1);
	int ft2 = ft_printf("ft2: x:%x, X:%X, p:%p\n", 42, -42, 0);
	ft_printf("ft2 len: %d\n", ft2);


	int rl1 = printf("\nrl1: s:%s, c:%c, percent:%%, i:%i, u:%u\n",
		(char *)NULL,
		0,
		INT32_MIN,
		-42);
	printf("rl1 len: %d\n", rl1);
	int rl2 = printf("rl2: x:%x, X:%X, p:%p\n", 42, -42, (void *)0);
	printf("rl2 len: %d\n", rl2);


	return (0);
}
*/
