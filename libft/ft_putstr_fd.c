/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 22:52:19 by julombar          #+#    #+#             */
/*   Updated: 2024/06/13 21:30:43 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
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
}
/*
int	main(void)
{
	char	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	char	*str1 = "une premiere ligne de code...";

	if (fd == -1)
	{
		perror("Error\n");
		return (1);
	}
	ft_putstr_fd(str1, fd);
	close(fd);

	return (0);
}
*/
