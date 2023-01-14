/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avapaill <avapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:18:57 by avapaill          #+#    #+#             */
/*   Updated: 2023/01/14 16:09:50 by avapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*line;
	char		*string_read;
	size_t		size_remain;
	int			index_for_newline;

	string_read = malloc(sizeof(char) * BUFFER_SIZE);
	if (!string_read)
		return ((void *) 0);
	read_new_buffer(string_read, fd);
	if (read(fd, string_read, sizeof(char) * BUFFER_SIZE) == -1)
		return (-1);
	index_for_newline = find_index(string_read, '\n');
	if (index_for_newline != -1)
	{
		size_remain = ft_strlen(string_read) - index_for_newline + 1;
		remain = malloc(sizeof(char) * (size_remain));
		if (!remain)
			return ((void *) 0);
		ft_strlcpy(remain, string_read + index_for_newline + 1, size_remain);
	}
	line = malloc(sizeof(char) * (index_for_newline + 1));
	if (!line)
		return ((void *) 0);
	ft_strlcpy(line, string_read, index_for_newline + 1);
	return (line);
}
