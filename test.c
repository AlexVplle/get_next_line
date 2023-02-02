# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "get_next_line.h"

int main(int argc, char const *argv[])
{
	char *test;
	int fd = open("test.txt", O_RDONLY);
	test = get_next_line(fd);
	while (test) {
		printf("%s", test);
		test = get_next_line(fd);
	}
	return 0;
}
