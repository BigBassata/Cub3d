/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 22:04:10 by julombar          #+#    #+#             */
/*   Updated: 2024/06/07 23:03:45 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}
/*
int	main(void)
{
	int	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

	if (fd == -1)
	{
		perror("Error\n");
		return (1);
	}
	ft_putchar_fd('c', fd);
	close(fd);

	return (0);
}
*/
