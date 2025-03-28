/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:06:40 by julombar          #+#    #+#             */
/*   Updated: 2024/06/13 21:33:11 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], sizeof(char));
		i++;
	}
	write(fd, "\n", 1);
}
/*
int	main(void)
{
	int	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	char	*str1 = "Une deuxieme ligne de code !!!";

	if (fd == -1)
	{
		perror("error\n");
		return (1);
	}
	ft_putendl_fd(str1, fd);
	close(fd);

	return (0);
}
*/
