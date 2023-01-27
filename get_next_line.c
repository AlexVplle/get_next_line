/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avapaill <avapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:18:57 by avapaill          #+#    #+#             */
/*   Updated: 2023/01/27 01:59:55 by avapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*line;
	int	index;

	if (fd < 0 && fd > 1024)
		return ((void *) 0);
	line = "";
	get_line(line, fd);
	return (line);
}

char	*get_line(char *line, int fd)
{
	char		*string_read;
	ssize_t	result_read;

	string_read = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!string_read)
		return ((void *) 0);
	result_read = read(fd, string_read, sizeof(char) * BUFFER_SIZE);
	while (result_read == sizeof(char) * BUFFER_SIZE)
	{
		printf("%d\n", find_index(string_read, '\n'));
		if (find_index(string_read, '\n') != -1)
		{
			string_read[find_index(string_read, '\n') + 1] = '\0';
			line = ft_strjoin(line, string_read);
			return (line);
		}
		line = ft_strjoin(line, string_read);
		result_read = read(fd, string_read, sizeof(char) * BUFFER_SIZE);
	}
	if (result_read == -1)
	{
		free(line);
		free(string_read);
		return ((void *) 0);
	}
	return (line);
}
