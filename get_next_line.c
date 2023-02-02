/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avapaill <avapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:18:57 by avapaill          #+#    #+#             */
/*   Updated: 2023/02/01 22:58:23 by avapaill         ###   ########.fr       */
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
	char		*string_read;
	ssize_t	result_read;
	int	index;

	if (fd < 0 || BUFFER_SIZE < 1)
		return ((void *) 0);
	line = "";
	if (remain)
	{
		line = ft_strjoin(remain, line);
		free(remain);
		remain = (void *) 0;
	}
	string_read = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!string_read)
		return ((void *) 0);
	result_read = read(fd, string_read, sizeof(char) * BUFFER_SIZE);
	while (result_read == sizeof(char) * BUFFER_SIZE)
	{
		index = find_index(string_read, '\n');
		if (index != -1)
		{
			remain = malloc(sizeof(char) * (BUFFER_SIZE - index));
			if (!remain)
				return ((void *) 0);
			ft_strlcpy(remain, string_read + index + 1, BUFFER_SIZE - index);
			string_read[index + 1] = '\0';
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
