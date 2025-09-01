#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  /* char *test = malloc(sizeof(char) * 10); */
  int fd = open("test.txt", O_RDONLY);
  get_next_line(fd);
  /* printf("%s", test); */
  /* test = get_next_line(fd); */
  /* printf("%s", test); */
  /* while (test) { */
  /*   test = get_next_line(fd); */
  /*   printf("%s", test); */
  /*  } */
  return 0;
}
