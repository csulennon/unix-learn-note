#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int st = socket(AF_INET, SOCK_STREAM, 0);
	if (st == -1)
	{
		printf("创建socket失败!%m\n");
	}

	struct sockaddr_in addr; // 定义一个ip地址的结构
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(7891);
	addr.sin_addr.s_addr = inet_addr("192.168.8.132");
	if (connect(st, (struct sockaddr*) &addr, sizeof(addr)) == -1)
	{
		printf("打开连接失败！%m\n");
		return EXIT_FAILURE;
	}

	char buf[100];
	memset(buf, 0, sizeof(buf));
	strcpy(buf, "你好世界！\n");
	if (send(st, buf, strlen(buf), 0) == -1)
	{
		printf("发送出错!%m\n");
		return EXIT_FAILURE;
	}

	sleep(3);

	close(st);

	return EXIT_SUCCESS;

}

