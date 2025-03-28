/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:05:33 by julombar          #+#    #+#             */
/*   Updated: 2024/07/14 20:53:11 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*upgrade_mem(char *next_line, int cpy_len, int *mem_size)
{
	char	*new_alloc;
	int		new_len;

	if (*mem_size > 2147483647 / 2)
		return (NULL);
	*mem_size *= 2;
	new_alloc = (char *)malloc(*mem_size * sizeof(char));
	if (!new_alloc)
	{
		free(next_line);
		return (NULL);
	}
	new_len = 0;
	while (new_len != cpy_len)
	{
		new_alloc[new_len] = next_line[new_len];
		new_len++;
	}
	free(next_line);
	while (new_len < *mem_size)
	{
		new_alloc[new_len] = '\0';
		new_len++;
	}
	return (new_alloc);
}

static int	load_buffer(int fd, char *buffer, int *buff_pos)
{
	int	size_read;

	*buff_pos = 0;
	size_read = read(fd, buffer, BUFFER_SIZE);
	buffer[size_read] = '\0';
	return (size_read);
}

static char	*handle_next_line_cpy(int fd, char *buffer,
									char *next_line, int *mem_size)
{
	static int	buff_len = 0;
	static int	buff_pos = 0;
	int			cpy_len;

	cpy_len = 0;
	if (buff_pos >= buff_len || !next_line || fd < 0)
	{
		if (next_line || fd >= 0)
			buff_len = load_buffer(fd, buffer, &buff_pos);
		if (buff_len <= 0 || ! next_line || fd < 0)
			return (error_or_eof(&buff_len, &buff_pos, next_line, cpy_len));
	}
	while (buffer[buff_pos] != '\n')
	{
		cpy_char(next_line, &cpy_len, buffer, &buff_pos);
		if (cpy_len + 1 >= *mem_size)
			next_line = upgrade_mem(next_line, cpy_len, mem_size);
		if (buff_pos >= buff_len)
			buff_len = load_buffer(fd, buffer, &buff_pos);
		if (buff_len <= 0 || !next_line)
			return (error_or_eof(&buff_len, &buff_pos, next_line, cpy_len));
	}
	if (buffer[buff_pos] == '\n')
		return (end_next_line(next_line, cpy_len, &buff_pos, '\n'));
	return (next_line);
}

static void	check_reset_buff(char *buffer, char *next_line)
{
	int	len;

	len = 0;
	while (next_line[len] != '\0')
		len++;
	if (len == 0)
		reset_buff(buffer);
	else if (len > 0)
	{	
		if (next_line[len - 1] != '\n')
			reset_buff(buffer);
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	char		*next_line;
	int			mem_size;

	mem_size = 2;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		next_line = handle_next_line_cpy(-1, buffer, NULL, &mem_size);
		reset_buff(buffer);
		return (NULL);
	}
	next_line = (char *)malloc(mem_size * sizeof(char));
	if (!next_line)
	{
		next_line = handle_next_line_cpy(fd, buffer, next_line, &mem_size);
		reset_buff(buffer);
		return (NULL);
	}
	next_line = handle_next_line_cpy(fd, buffer, next_line, &mem_size);
	next_line = resize_nl(next_line);
	if (next_line == NULL)
		reset_buff(buffer);
	else
		check_reset_buff(buffer, next_line);
	return (next_line);
}
/*
int	main(int argc, char *argv[]) {
	int	fd;
	char *str;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (1);
		printf("Case_1 - argc:%i\n", argc);	
		printf("fd:%i\n", fd);	
	}
	else if (argc == 3)
	{
		int fd1 = open(argv[1], O_RDONLY);
		if (fd1 == -1)
			return (1);

		fd = open(argv[2], O_RDONLY);
		if (fd == -1)
			return (1);

		printf("Cqse_2 - argc:%i\n", argc);	
		printf("BUFFER_SIZE: %i\n", BUFFER_SIZE);
		for (int i = 1; i < 12; i++)
		{
			str = get_next_line(fd1);
			if (!str)
				printf("[result%i: NULL]", i);
			else if (str)
			{
				printf("result%i: %s", i, str);
				free(str);
			}
		}
		printf("\n");
	}
	else if (argc == 1)
		fd = 0;

	printf("BUFFER_SIZE: %i\n", BUFFER_SIZE);
	for (int i = 1; i < 12; i++)
	{
		str = get_next_line(fd);
		if (!str)
			printf("[result%i: NULL]", i);
		else if (str)
		{
			printf("result%i: %s", i, str);
			free(str);
		}
	}
	int invalid_fd = 42;
	char *str2 = get_next_line(invalid_fd);
	if (!str2)
		printf("\n\n[invalid_fd_test: NULL]");
	else if (str2)
	{
		printf("invalid_fd: %s", str2);
		free(str2);
	}

	if (fd != 0)
		close(fd);

    return (0);
}
*/
