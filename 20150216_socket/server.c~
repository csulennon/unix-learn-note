#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

int main()
{
	int st = socket(AF_INET, SOCK_STREAM, 0);
	if (st == -1)
	{
		printf("创建socket失败!%m\n");
		return EXIT_FAILURE;
	}

	// 将地址设置为可重用
	int on = 1;
	if (setsockopt(st, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1)
	{
		printf("setsockopt failed %s\n", strerror(errno));
		return EXIT_FAILURE;
	}

	struct sockaddr_in addr; // 定义一个ip地址的结构
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(7891);
	addr.sin_addr.s_addr = htonl(INADDR_ANY); // 接受本机所有ip

	if (bind(st, (struct sockaddr*) &addr, sizeof(addr)) == -1)
	{
		printf("服务器绑定地址出错！%m\n");
		return EXIT_FAILURE;
	}

	if (listen(st, 20) == -1) // 同时接受20个连接
	{
		printf("服务器监听出错！%m\n");
		return EXIT_FAILURE;
	}

	char buf[100];
	memset(buf, 0, sizeof(buf));

	struct sockaddr_in clientaddr;
	void* clientaddrp = &clientaddr;
	int client_st;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		memset(clientaddrp, 0, sizeof(clientaddr));
		socklen_t len = sizeof(clientaddr);
		client_st = accept(st, clientaddrp, &len);
		if (client_st == -1)
		{
			printf("accept 出错：%m\n");
			return EXIT_FAILURE;
		}
		
		// 打印ip地址
		printf("%s说：", inet_ntoa(clientaddr.sin_addr));

		while (1)
		{
			int rcv_num = recv(client_st, buf, sizeof(buf), 0);
			if (rcv_num > 0)
			{
				printf("%s", buf);
			}
			else
			{
				if (rcv_num == 0)
				{
					printf("客户端正常关闭退出！\n");
				}
				else
				{
					printf("接收出错：%m\n");
					close(client_st);
				}
				break;
			}
		}

	}

	close(st);

	return EXIT_SUCCESS;

}

