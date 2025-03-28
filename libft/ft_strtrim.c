/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:09:30 by julombar          #+#    #+#             */
/*   Updated: 2024/06/14 17:50:11 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

static size_t	count_from_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				counter++;
				j = 0;
				break ;
			}
			j++;
		}
		if (set[j] == '\0')
			break ;
		i++;
	}
	return (counter);
}

static size_t	count_from_end(char const *s1, char const *set, size_t s1_len)
{
	size_t	i;
	size_t	j;
	size_t	counter;

	i = s1_len - 1;
	counter = 0;
	while (1)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				counter++;
				j = 0;
				break ;
			}
			j++;
		}
		if (set[j] == '\0' || i == 0)
			break ;
		i--;
	}
	return (counter);
}

static void	cpytrim(char const *s1, char *dest, size_t j, size_t dest_len)
{
	size_t	i;

	i = 0;
	while (i < dest_len && s1[j] != '\0')
	{
		dest[i] = s1[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	nb_start;
	size_t	nb_end;
	size_t	dest_len;
	char	*dest;

	if (s1 == NULL || set == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	nb_start = count_from_start(s1, set);
	nb_end = 0;
	if (s1_len > 0)
		nb_end = count_from_end(s1, set, s1_len);
	dest_len = 0;
	if (nb_start + nb_end < s1_len)
		dest_len = s1_len - nb_start - nb_end;
	dest = (char *)malloc(dest_len + 1);
	if (dest == NULL)
		return (NULL);
	cpytrim(s1, dest, nb_start, dest_len);
	return (dest);
}
/*
int	main(void)
{
	char	*str1 = "|||///Salut/Ca|Va|/";
	char	*set1 = "|/";
	char	*strtrim1 = ft_strtrim(str1, set1);
	char	*strtrim2 = ft_strtrim(str1, "");

	printf("\nstr1: %s\n", str1);
	printf("set1: %s\n", set1);
	printf("strtrim1: %s - [exp: Salut/Ca|Va ] \n", strtrim1);
	printf("strtrim2: %s - [exp: |||///Salut/Ca|Va|/ ] \n", strtrim2);

	if (strtrim1 != NULL)
		free(strtrim1);

	if (strtrim2 != NULL)
		free(strtrim2);

    char *s;
    s = ft_strtrim("   xxxtripouille", " x");
    printf("Test 1: %s\n", s); // Expected: "tripouille"
    free(s);

    s = ft_strtrim("tripouille   xxx", " x");
    printf("Test 2: %s\n", s); // Expected: "tripouille"
    free(s);

    s = ft_strtrim("   xxxtripouille   xxx", " x");
    printf("Test 3: %s\n", s); // Expected: "tripouille"
    free(s);

    s = ft_strtrim("   xxx   xxx", " x");
    printf("Test 4: %s\n", s); // Expected: ""
    free(s);

    s = ft_strtrim("", "123");
    printf("Test 5: %s\n", s); // Expected: ""
    free(s);

    s = ft_strtrim("123", "");
    printf("Test 6: %s\n", s); // Expected: "123"
    free(s);

    s = ft_strtrim("", "");
    printf("Test 7: %s\n", s); // Expected: ""
    free(s);

    s = ft_strtrim("abcdba", "acb");
    printf("Test 8: %s\n", s); // Expected: "d"
    free(s);

	return (0);
}
*/
