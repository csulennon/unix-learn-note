#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
typedef struct Person
{
	int 	id;
	char  	name[16];
	int 	age;
} Person;

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("参数错误:useage main filename.\n");
		exit(-1);
	}

	FILE *fp = fopen(argv[1], "a+");	
	if(NULL == fp)
	{
		printf("文件打开错误:%s\n", strerror(errno));
	}
	
	Person persons[4] = {
			{0,"樊列龙", 22},
			{1,"王少源", 92},
			{2,"fanlieloong", 22},
			{3,"wangshaoyuan", 92},
		};
	
	fwrite(&persons, sizeof(Person), 4, fp);
	
	fclose(fp);


	FILE* fpr = fopen(argv[1], "r");
	Person p;
	while(fread(&p, sizeof(Person), 1, fpr))
	{
		printf("id \t= %d\n", p.id);
		printf("name \t= %s\n", p.name);
		printf("age \t= %d\n", p.age);
		printf("\n\n");
	}
	return 0;
}
