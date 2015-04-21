#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	char buf[10];
	memset(buf, 0, sizeof(buf));
	int fd = open("fifo_file", O_WRONLY|O_RDONLY);
	printf("fd = %d\n", fd);
	while(1)
	{
		read(STDIN_FILENO, buf, sizeof(buf));
		if(buf[0] == '0')
		{
			break;
		}
		write(fd, buf, strlen(buf));
	}
	close(fd);

	return 0;
}

