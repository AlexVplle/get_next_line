/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avapaill <avapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:18:57 by avapaill          #+#    #+#             */
/*   Updated: 2023/01/26 12:43:26 by avapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*line;
	char		*string_read;
	ssize_t	result_read;

	if (fd < 0 && fd > 1024)
		return ((void *) 0);
	string_read = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!string_read)
		return ((void *) 0);
	line = "";
	result_read = read(fd, string_read, sizeof(char) * BUFFER_SIZE);
	while (result_read == sizeof(char) * BUFFER_SIZE) 
		line = ft_strjoin(line, string_read);
	if (result_read == -1)
	{
		free(line);
		free(string_read);
		return ((void *) 0);
	}
	return (line);
}
