#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int i;
    char str[100];
    printf("Enter the Byte data : ");
    gets(str);
    int len;
    len=strlen(str);
    char f,e,raw;
    printf("Enter the flag character :");
    scanf("%c",&f);
    scanf("%c",&raw);
    printf("Enter the escape character :");
    scanf("%c",&e);
    int count;
    for(i=0;i<len;i++)
    {
        if(str[i]==f || str[i]==e)
        {
            count++;
        }
    }
    int totalsize=len+count+2;
    char result[totalsize];
    for(i=0;i<len;i++)
        result[i]=str[i];
    for(i=0;i<totalsize;i++)
    {
        int pos=0;
        if(i==0 || i==totalsize-1)
        {
            pos=i;
            for(int j=totalsize-1;j>=pos;j--)
            {
                result[j]=result[j-1];
            }
            result[pos]=f;
            i=pos+1;
        }
        if(result[i]==f || result[i]==e)
        {
            pos=i;
            for(int j=totalsize-1;j>=pos;j--)
            {
                result[j]=result[j-1];
            }
            result[pos]=e;
            i=pos+1;
        }
    }
    printf("The stuffed data is : ");
    for(i=0;i<totalsize;i++)
    {
        printf("%c",result[i]);
    }
}
