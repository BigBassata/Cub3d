/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:18:21 by julombar          #+#    #+#             */
/*   Updated: 2024/10/08 16:18:46 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hexa(unsigned long nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr >= 16)
	{
		len += print_hexa(nbr / 16, base);
		len += print_char(base[nbr % 16]);
	}
	else if (nbr < 16)
		len += print_char(base[nbr]);
	return (len);
}

int	print_nbr(int nbr)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nbr < 0)
	{
		len += print_char('-');
		len += print_nbr(-nbr);
	}
	else if (nbr > 9)
	{
		len += print_nbr(nbr / 10);
		len += print_char(nbr % 10 + '0');
	}
	else if (nbr <= 9)
		len += print_char(nbr + '0');
	return (len);
}

int	print_ptr(void *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		len += print_str("(nil)");
	else
	{
		len += print_str("0x");
		len += print_hexa((unsigned long)ptr, "0123456789abcdef");
	}
	return (len);
}

int	print_str(char *str)
{
	int	len;

	if (!str)
		return (print_str("(null)"));
	len = 0;
	while (*str)
	{
		len += print_char(*str);
		str++;
	}
	return (len);
}

int	print_u(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr > 9)
	{
		len += print_nbr(nbr / 10);
		len += print_char(nbr % 10 + '0');
	}
	else if (nbr <= 9)
		len += print_char(nbr + '0');
	return (len);
}
