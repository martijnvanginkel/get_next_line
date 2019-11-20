/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-gin <mvan-gin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:25:38 by mvan-gin       #+#    #+#                */
/*   Updated: 2019/11/20 16:08:42 by mvan-gin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_bufsize(int fd, int *end_of_file)
{
	char			**resultpointer;
	char			*result;
	char			buf[BUFFER_SIZE + 1];
	int				bytes_read;
	int				x;

	x = 0;
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read == -1)
		return (0);
	if (bytes_read == 0)
		*end_of_file = 1;
	buf[BUFFER_SIZE] = '\0';
	result = malloc(sizeof(char) * (bytes_read + 1));
	if (!result)
		return (0);
	while (x < bytes_read)
	{
		result[x] = buf[x];
		x++;
	}
	result[x] = '\0';
	resultpointer = &result;
	return (result);
}

int		get_next_line(int fd, char **line)
{
	static char		*waitingline;
	char			*temp;
	int				end_of_file;

	if (!fd || !line)
		return (-1);
	end_of_file = 0;
	while (!enough_for_one_line(waitingline) && end_of_file != 1)
	{
		if (waitingline == 0)
		{
			waitingline = read_bufsize(fd, &end_of_file);
		}
		else
		{
			waitingline = strjoin(waitingline, read_bufsize(fd, &end_of_file));
		}
		if (!waitingline)
			return (-1);
	}
	if (end_of_file == 1)
	{
		*line = waitingline;
		waitingline = 0;
		free(waitingline);
		return (0);
	}
	*line = read_line(&waitingline);
	// free(*line);
	return (1);
}

// int main()
// {
// 	int fd;
// 	char	*str;

// 	fd = open("text.txt", O_RDONLY);

// 	while (get_next_line(fd, &str) == 1)
// 	{

// 	}

// 	while (1)
// 	{

// 	}

// 	return (0);
// }