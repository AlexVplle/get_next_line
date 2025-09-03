/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avapaill <avapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:43:05 by avapaill          #+#    #+#             */
/*   Updated: 2023/02/05 02:45:44 by avapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int find_index(char *to_find, char c) {
  size_t i;

  i = 0;
  while (to_find[i]) {
    if (c == to_find[i])
      return (i);
    i++;
  }
  return (-1);
}

size_t ft_strlen(const char *s) {
  size_t length;

  length = 0;
  while (s[length])
    length++;
  return (length);
}

char *ft_strcat(char *dest, const char *src) {
  int dest_length;
  int i;

  dest_length = ft_strlen(dest);
  i = 0;
  while (src[i]) {
    dest[dest_length + i] = src[i];
    i++;
  }
  dest[dest_length + i] = '\0';
  return (dest);
}

char *ft_strjoin(char const *s1, char const *s2) {
  char *dest;

  if (!s1 || !s2)
    return ((void *)0);
  dest = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
  if (!dest)
    return ((void *)0);
  *dest = '\0';
  dest = ft_strcat(dest, s1);
  return (ft_strcat(dest, s2));
}

size_t ft_strlcpy(char *dst, const char *src, size_t size) {
  size_t i;
  size_t length;

  length = ft_strlen(src);
  if (!dst)
    return (length);
  i = 0;
  while (i + 1 < size && src[i]) {
    dst[i] = src[i];
    i++;
  }
  if (i < size)
    dst[i] = '\0';
  return (length);
}
