#include <stdio.h>
#include <string.h>

int main()
{
	char server[10000];
	while(1)
	{
		printf("Client :");
		gets(server);
		if(strcmp("hi server",server)==0)
		{
			printf("server : hi client\n");
		}
		else if(strcmp("how are you",server)==0)
		{
			printf("server : Fine\n");
		}
		else if(strcmp("quit",server)==0)
		{
			printf("quit\n");
			break;
		}
	}

}