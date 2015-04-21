#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
	int len = 0;
	char buf[10];
	memset(buf, 0, sizeof(buf));
	int fd = open("fifo_file", O_RDONLY);
	while((len = read(fd, buf, sizeof(buf))) > 0)
	{
		//write(STDOUT_FILENO, buf, len);
		printf("%s\n", buf);
		memset(buf, 0, sizeof(buf));
	}
	close(fd);

	return 0;
}

