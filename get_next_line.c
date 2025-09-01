/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avapaill <avapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:18:57 by avapaill          #+#    #+#             */
/*   Updated: 2023/02/05 03:55:46 by avapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd) {
  static char *remain;
  char *line;
  char *string_read;
  int index;

  if (fd < 0 || BUFFER_SIZE < 1)
    return ((void *)0);
  line = malloc(sizeof(char) * 1);
  if (!line) {
    return ((void *)0);
  }
  *line = '\0';
  /* if (remain) */
  /* { */
  /* 	line = ft_strjoin(remain, line); */
  /* 	free(remain); */
  /* 	remain = ((void *) 0); */
  /* } */
  string_read = malloc(sizeof(char) * (BUFFER_SIZE + 1));
  if (!string_read) {
    free(remain);
    return ((void *)0);
  }
  index = get_line(string_read, line, fd);
  printf("%s", line);
  if (index == -2)
    return ((void *)0);
  line = separate_string(remain, string_read, line, index);
  return (line);
}

int get_line(char *string_read, char *line, int fd) {
  ssize_t result_read;
  int index;

  result_read = read(fd, string_read, sizeof(char) * BUFFER_SIZE);
  string_read[result_read] = '\0';
  index = find_index(string_read, '\n');
  while (result_read && index == -1) {
    line = ft_strjoin(line, string_read);
    result_read = read(fd, string_read, sizeof(char) * BUFFER_SIZE);
    if (result_read == -1)
      return (-2);
    string_read[result_read] = '\0';
    index = find_index(string_read, '\n');
  }
  return (index);
}

char *separate_string(char *remain, char *string_read, char *line, int index) {
  remain = malloc(sizeof(char) * (BUFFER_SIZE - index));
  if (!remain)
    return ((void *)0);
  ft_strlcpy(remain, string_read + index + 1, BUFFER_SIZE - index);
  string_read[index + 1] = '\0';
  line = ft_strjoin(line, string_read);
  return (line);
}
