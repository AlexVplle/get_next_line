/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avapaill <avapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:51:16 by avapaill          #+#    #+#             */
/*   Updated: 2023/02/05 03:49:59 by avapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

int find_index(char *to_find, char c);
int get_line(char *string_read, char **line, int fd);
size_t ft_strlen(const char *s);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
char *get_next_line(int fd);
char *ft_strcat(char *dest, const char *src);
char *ft_strjoin(char const *s1, char const *s2);
char *separate_string(char **remain, char *string_read, char *line, int index);

#endif
