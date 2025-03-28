/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:45:35 by julombar          #+#    #+#             */
/*   Updated: 2024/06/14 17:43:36 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	char	*min_case;
	char	temp;

	min_case = "-2147483648";
	if (n == -2147483648)
		ft_putstr_fd(min_case, fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n * -1, fd);
	}
	else if (n >= 0 && n <= 9)
	{
		temp = n + '0';
		ft_putchar_fd(temp, fd);
	}
	else if (n >= 10)
	{
		temp = n % 10 + '0';
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(temp, fd);
	}
}
/*
int	main(void)
{
	int	nb1 = 42;
	int	nb2 = -42;
	int	nb3 = 0;
	int	nb4 = 2147483647;
	int	nb5 = -2147483647;
	int	nb6 = -2147483648;

	int	fd1 = open("test.txt1", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	int	fd2 = open("test.txt2", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	int	fd3 = open("test.txt3", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	int	fd4 = open("test.txt4", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	int	fd5 = open("test.txt5", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	int	fd6 = open("test.txt6", O_WRONLY | O_CREAT | O_TRUNC, 0666);

	if (fd1 == -1  || fd2 == -1 || fd3 == -1 || fd4 == -1
			|| fd5 == -1 || fd6 == -1)
	{
		perror("Error\n");
		return (0);
	}
	ft_putnbr_fd(nb1, fd1);
	ft_putnbr_fd(nb2, fd2);
	ft_putnbr_fd(nb3, fd3);
	ft_putnbr_fd(nb4, fd4);
	ft_putnbr_fd(nb5, fd5);
	ft_putnbr_fd(nb6, fd6);

	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	close(fd6);

	return (0);
}
*/
