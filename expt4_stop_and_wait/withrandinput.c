#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int resend(int x)
{
    printf("Resending frame %d\n",x);
    printf("Acknowledge from %d frame\n",x);
}
int main()
{
    int n;
    printf("No of Frames :");
    scanf("%d",&n);
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        if(rand()%5==0)
        {
            printf("Sending frame %d\n",i);
            printf("wait for 1 second\n");
            sleep(5);
            resend(i);
        }
        else
        {
            printf("Sending frame %d\n",i);
            printf("Acknowledge from %d frame\n",i);
        }
    }
}
