#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

int main()
{
    int n;
    printf("Enter no. of frames : ");
    scanf("%d",&n);
    int m;
    printf("Enter the frame value :");
    scanf("%d",&m);
    for(int i=0;i<n;i++)
    {
        printf("sending frame %d \n",i);
    }
    printf("Acknowledge frame from %d\n",m-1);
    sleep(2);
    for(int i=m-1;i<n;i++)
    {
        printf("Retransmitting frame %d\n",i);
    }

}

