# include <fcntl.h>
# include <stdio.h>
#include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

int main(int argc, char const *argv[])
{
	char *test = malloc(sizeof(char) * 6);
	int fd = open("test.txt", O_RDONLY);
	test = get_next_line(fd);
	printf("%s", test);
	test = get_next_line(fd);
	printf("%s", test);
	// while (test) {
	// 	test = get_next_line(fd);
	// 	// printf("%s", test);
	// }
	return 0;
}
