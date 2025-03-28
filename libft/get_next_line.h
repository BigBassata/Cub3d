/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julombar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:03:11 by julombar          #+#    #+#             */
/*   Updated: 2024/07/14 20:39:55 by julombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

char	*get_next_line(int fd);
void	cpy_char(char *next_line, int *cpy_len, char *buffer, int *buff_pos);
char	*end_next_line(char *next_line, int cpy_len,
			int *buff_pos, int end_char);
char	*error_or_eof(int *buff_len, int *buff_pos,
			char *next_line, int cpy_len);
void	reset_buff(char *buffer);
char	*resize_nl(char *str);

#endif
