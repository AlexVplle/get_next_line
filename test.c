# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

int main(int argc, char const *argv[])
{
	char test[30];
	int fd = open("test.txt", O_RDONLY);
	read(fd, test, 2);
	printf("%s", test);
	return 0;
}
