#include<stdio.h>
#include<string.h>
#define MAX_LEN 1000
int power(int a, int y)
{
    int mul=1;
    for (int i=0;i<y;i++)
    {
        mul=mul*a;
    }
    return mul;
}
int get_decimal(int size,int array[])
{
    int sum=0;
    for(int i=0;i<size;i++)
    {
        if(array[i]==1)
        {
        sum=sum+power(2,(size-1)-i);
        }
    }
    return sum;
}
int getrem(int divisor_size,int dividend_size,int divisor[],int dividend[])
{
    int k=(dividend_size-divisor_size)+1;
    int num=0;
    while(num!=k)
    {
        int temp[dividend_size];
        for(int i=0;i<dividend_size;i++)
        {
            temp[i]=0;
        }
        if(dividend[num]==1)
        {
            for(int i=0;i<divisor_size;i++)
            {
                temp[i+num]=divisor[i];
            }
            for(int i=0;i<dividend_size;i++)
            {
                  dividend[i]=dividend[i]^temp[i];
            }
        }
        else
        {
            for(int i=0;i<dividend_size;i++)
            {
                dividend[i]=dividend[i]^temp[i];
            }
        }
        num=num+1;
    }
    return 0;
}
int main()
{
    char get_divisor[MAX_LEN];
    char get_dividend[MAX_LEN];
    printf("Enter the value of divisor : ");
    scanf("%s",get_divisor);
    printf("Enter the value of dividend : ");
    scanf("%s",get_dividend);
    int divisor_size=strlen(get_divisor);
    int actual_size=strlen(get_dividend);
    int dividend_size=actual_size+(divisor_size-1);
    int divisor[divisor_size];
    int dividend[dividend_size];
    int codeword[dividend_size];
    for(int i=0;i<divisor_size;i++)
    {
        int a = get_divisor[i];
        if(a==49)
        divisor[i]=1;
        else
        divisor[i]=0;
    }
    for(int i=0;i<dividend_size;i++)
    {
        dividend[i]=0;
    }
    for(int i=0;i<dividend_size;i++)
    {
        int a = get_dividend[i];
        if(a==49)
        dividend[i]=1;
        else
        dividend[i]=0;
    }
    for(int i=0;i<actual_size;i++)
    {
        codeword[i]=dividend[i];
    }
    if(get_decimal(actual_size,dividend)>get_decimal(divisor_size,divisor))
    {
    getrem(divisor_size,dividend_size,divisor,dividend);
    printf("\nThe reminder is :");
    for(int i=actual_size;i<dividend_size;i++)
    {
        printf("%d",dividend[i]);
    }
    for(int i=actual_size;i<dividend_size;i++)
    {
        codeword[i]=dividend[i];
    }
    printf("\nThe code word is :");
    for(int i=0;i<dividend_size;i++)
    {
        printf("%d",codeword[i]);
    }
    printf("\nThe reminder bit is appended to the original data.....\n\n");
    char rx_str[dividend_size];
    printf("Enter the value of Receiver signal : ");
    scanf("%s",rx_str);
    int rx[dividend_size];
    for(int i=0;i<dividend_size;i++)
    {
        int a = rx_str[i];
        if(a==49)
        rx[i]=1;
        else
        rx[i]=0;
    }
    int syn[divisor_size-1];
    getrem(divisor_size,dividend_size,divisor,rx);
    int a=0;
    for(int i=actual_size;i<dividend_size;i++)
    {
        syn[a]=rx[i];
        a=a+1;
    }
    int flag=0;
    for(int i=0;i<divisor_size-1;i++)
    {
        if(syn[i]==1)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("Receiver : no error");
    }
    else
    {
        for(int i=0;i<divisor_size-1;i++)
    {
        printf("%d",syn[i]);
    }
    printf("\nReceiver side error");
    }
    }
}