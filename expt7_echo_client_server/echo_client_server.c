#include <stdio.h>
#include <string.h>

int main()
{
	char server[10000];
	while(1)
	{
		printf("Client :");
		gets(server);
		if(strcmp("ds",server)==0)
		{
			printf("socket closed");
			break;
		}
		else
		{
			printf("Server : %s",server);
		}
	}

}