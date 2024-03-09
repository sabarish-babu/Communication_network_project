#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

int main()
{
    int n;
    printf("Enter no. of frames : ");
    scanf("%d",&n);
    int m;
    printf("Enter the frame want to retransmit :");
    scanf("%d",&m);
    int data[m];
    for(int i=0;i<m;i++)
    {
        printf("Enter the %d frame",i);
        scanf("%d",&data[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("sending frame %d \n",i);
    }
    int temp =0;
    for (int i = 0; i < m; i++) {
        for (int j = i+1; j < m; j++) {
           if(data[i] > data[j]) {
               temp = data[i];
               data[i] = data[j];
               data[j] = temp;
           }
        }
    }
    sleep(2);
    int a=0;
    for(int i=0;i<n;i++)
    {
        if(i==data[a])
        {
            printf("acknowledge frame from %d\n",i);
            printf("retransmitting frame %d\n",i);
            a=a+1;
            sleep(2);
        }
    }
}
