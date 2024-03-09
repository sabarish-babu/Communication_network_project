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
    int d;
    printf("Enter the frame wants to resend :");
    scanf("%d",&d);
    int data[d];
    for(int i=0;i<d;i++)
    {
        printf("Enter the %d data frame :",i+1);
        scanf("%d",&data[i]);
    }
    int temp =0;
    for (int i = 0; i < d; i++) {
        for (int j = i+1; j < d; j++) {
           if(data[i] > data[j]) {
               temp = data[i];
               data[i] = data[j];
               data[j] = temp;
           }
        }
    }
    int a=0;
    for(int i=0;i<n;i++)
    {
        if(i==data[a]-1)
        {
            printf("Sending frame %d\n",i);
            printf("wait for 1 second\n");
            sleep(1);
            resend(i);
            a=a+1;
        }
        else
        {
            printf("Sending frame %d\n",i);
            printf("Acknowledge from %d frame\n",i);
        }
    }
}
