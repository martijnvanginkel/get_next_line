/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-gin <mvan-gin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 13:07:10 by mvan-gin       #+#    #+#                */
/*   Updated: 2019/11/20 13:56:41 by mvan-gin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int		enough_for_one_line(char *line);
char	*read_bufsize(int fd, int *end_of_file);
char	*read_line(char **waitingline);
char	*strjoin(char *s1, char *s2);
int		get_strlen(char *str);

#endif
