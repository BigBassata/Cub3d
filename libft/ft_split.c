/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 22:26:31 by julombar          #+#    #+#             */
/*   Updated: 2024/06/12 23:43:58 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_strs(const char *s, char c)
{
	size_t	i;
	size_t	count;
	int		in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static char	**free_arr(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**init_str(const char *s, char c, char **str_arr, size_t nb_str)
{
	size_t	i;
	size_t	str_len;
	size_t	str_index;

	str_index = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			str_len = 0;
			while (s[i + str_len] != '\0' && s[i + str_len] != c)
				str_len++;
			str_arr[str_index] = (char *)malloc((str_len + 1) * sizeof(char));
			if (str_arr[str_index] == NULL)
				return (free_arr(str_arr, str_index));
			str_index++;
			i += str_len;
		}
		else
			i++;
	}
	str_arr[nb_str] = NULL;
	return (str_arr);
}

static void	cpy_strs(const char *s, char c, char **str_arr)
{
	size_t	i;
	size_t	j;
	size_t	str_index;

	i = 0;
	str_index = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i] != '\0' && s[i] != c)
			{
				str_arr[str_index][j] = s[i];
				i++;
				j++;
			}
			str_arr[str_index][j] = '\0';
			str_index++;
		}
		else
			i++;
	}
}

char	**ft_split(const char *s, char c)
{
	size_t	nb_str;
	char	**str_arr;

	if (s == NULL)
		return (NULL);
	nb_str = count_strs(s, c);
	if (nb_str == 0)
	{
		str_arr = (char **)malloc(sizeof(char *));
		if (str_arr == NULL)
			return (NULL);
		str_arr[0] = NULL;
		return (str_arr);
	}
	str_arr = (char **)malloc((nb_str + 1) * sizeof(char *));
	if (str_arr == NULL)
		return (NULL);
	str_arr = init_str(s, c, str_arr, nb_str);
	if (str_arr == NULL)
		return (NULL);
	cpy_strs(s, c, str_arr);
	return (str_arr);
}
