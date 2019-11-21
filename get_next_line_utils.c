/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-gin <mvan-gin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 13:05:24 by mvan-gin       #+#    #+#                */
/*   Updated: 2019/11/21 12:34:47 by mvan-gin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_strlen(char *str)
{
	int x;

	x = 0;
	if (!str)
	{
		return (0);
	}
	while (str[x] != '\0')
	{
		x++;
	}
	return (x);
}

char		*strjoin(char *s1, char *s2)
{
	char		*result;
	int			x;
	int			y;

	x = 0;
	y = 0;
	if (s1 == 0)
		return (0);
	result = malloc(sizeof(char) * (get_strlen(s1) + get_strlen(s2) + 1));
	if (!result)
		return (0);
	while (s1[x] != '\0')
	{
		result[x] = s1[x];
		x++;
	}
	while (s2[y] != '\0')
	{
		result[x] = s2[y];
		x++;
		y++;
	}
	result[x] = '\0';
	return (result);
}

char		*cut_str_till(char *buf, int str_size)
{
	int		x;
	char	*result;

	x = 0;
	result = malloc(sizeof(char) * (str_size + 1));
	if (!result)
	{
		return (0);
	}
	while (x < str_size)
	{
		result[x] = buf[x];
		x++;
	}
	result[x] = '\0';
	return (result);
}

char		*read_line(char **waitingline)
{
	char	*result;
	int		linelen;
	int		x;

	x = 0;
	result = 0;
	linelen = get_strlen(*waitingline);
	while (x < linelen)
	{
		if ((*waitingline)[x] == '\n')
		{
			result = cut_str_till(*waitingline, x);		
			*waitingline = &(*waitingline)[x + 1];
			return (result);
		}
		x++;
	}
	return (0);
}

int			enough_for_one_line(char *line)
{
	int x;

	x = 0;
	if (line == 0)
	{
		return (0);
	}
	while (line[x] != '\0')
	{
		if (line[x] == '\n')
		{
			return (1);
		}
		x++;
	}
	return (0);
}
