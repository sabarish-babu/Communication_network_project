#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int i;
    char str[100];
    printf("Enter the data : ");
    gets(str);
    int len;
    len=strlen(str);
    char f,e,raw;
    printf("Enter the flag character :");
    scanf("%c",&f);
    scanf("%c",&raw);
    printf("Enter the escape character :");
    scanf("%c",&e);
    char result[len];
    for(i=0;i<len;i++)
        result[i]=str[i];

    for(i=0;i<len;i++)
    {
        int pos=0;
        if(i==0 || i==len-1)
        {
            pos=i;
            for(int j=pos;j<len;j++)
            {
                result[j]=result[j+1];
            }
            len--;
            i=pos+1;
        }
        if(result[i]==f || result[i]==e)
        {
            pos=i;
            for(int j=pos;j<len;j++)
            {
                result[j]=result[j+1];
            }
            len--;
            i=pos;
        }
    }
    printf("The destuffed data is : ");
    for(i=0;i<len;i++)
    {
        printf("%c",result[i]);
    }
}
