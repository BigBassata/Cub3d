/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:08:02 by julombar          #+#    #+#             */
/*   Updated: 2024/07/14 20:55:50 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	cpy_char(char *next_line, int *cpy_len, char *buffer, int *buff_pos)
{
	next_line[*cpy_len] = buffer[*buff_pos];
	(*buff_pos)++;
	(*cpy_len)++;
}

char	*end_next_line(char *next_line, int cpy_len,
						int *buff_pos, int end_char)
{
	if (end_char == '\n')
	{
		next_line[cpy_len] = '\n';
		next_line[cpy_len + 1] = '\0';
		*buff_pos += 1;
		return (next_line);
	}
	else
	{
		*buff_pos = 0;
		next_line[cpy_len] = '\0';
		return (next_line);
	}
}

char	*error_or_eof(int *buff_len, int *buff_pos,
						char *next_line, int cpy_len)
{
	if (!next_line)
	{
		*buff_len = 0;
		*buff_pos = 0;
		return (NULL);
	}
	else if (*buff_len < 0)
	{
		*buff_len = 0;
		*buff_pos = 0;
		free(next_line);
		return (NULL);
	}
	else if (*buff_len == 0 && cpy_len == 0)
	{
		*buff_len = 0;
		*buff_pos = 0;
		free(next_line);
		return (NULL);
	}
	else
	{
		*buff_len = 0;
		return (end_next_line(next_line, cpy_len, buff_pos, '\0'));
	}
}

void	reset_buff(char *buffer)
{
	int	len;

	len = 0;
	while (len < BUFFER_SIZE + 1)
	{
		buffer[len] = '\0';
		len++;
	}
}

char	*resize_nl(char *str)
{
	char	*new_str;
	int		len;

	if (!str)
		return (NULL);
	len = 0;
	while (str[len])
		len++;
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	len = 0;
	while (str[len])
	{
		new_str[len] = str[len];
		len++;
	}
	new_str[len] = '\0';
	free(str);
	return (new_str);
}
