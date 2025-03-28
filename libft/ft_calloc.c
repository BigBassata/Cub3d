/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 21:44:01 by julombar          #+#    #+#             */
/*   Updated: 2024/06/14 15:36:53 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	void			*arr;
	unsigned char	*temp;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	arr = malloc(nmemb * size);
	if (arr == NULL)
		return (NULL);
	i = 0;
	temp = arr;
	while (i < nmemb * size)
	{
		temp[i] = 0;
		i++;
	}
	return (arr);
}
/*
int	main(void)
{
	char *char_test = (char *)ft_calloc(5, 1);
	int *int_test = (int *)ft_calloc(5, 4);


	printf("\narr char: %s\n", char_test);
	printf("\narr int: ");
	for (int i = 0; i < 5; i++)
	{
		printf(" %d ", int_test[i]);
	}
	printf("\n");

	if (char_test != NULL)
		free(char_test);
	if (int_test != NULL)
		free(int_test);
	return (0);
}
*/
