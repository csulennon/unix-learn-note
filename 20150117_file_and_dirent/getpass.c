#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* pas = getpass("please input password:");
	write(STDOUT_FILENO, pas, strlen(pas));
	write(STDOUT_FILENO, "\n", strlen("\n"));

	return 0;
}
