#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000
int changetoint(int len, char array[],int code[])
{
    for(int i=0;i<len;i++)
    {
        int b = array[i];
        if(b==49)
        code[i]=1;
        else
        code[i]=0;
    }
    return 0;
}
int countoffiveones(int len , int code[])
{
    int count=0;
    for(int i=0;i<len;i++)
    {
        if(code[i]==1 && code[i+1]==1&& code[i+2]==1&& code[i+3]==1&& code[i+4]==1)
        {
            count+=1;
            i=i+4;
        }
    }
    return count;
}
int decryptdata(int size, int decryptarr[])
{
    for(int i=0;i<size;i++)
    {
        int pos=0;
        if(decryptarr[i]==1 && decryptarr[i+1]==1&& decryptarr[i+2]==1&& decryptarr[i+3]==1&& decryptarr[i+4]==1)
        {
            pos=i+5;
            for(int j=pos;j<=size;j++)
            {
                decryptarr[j]=decryptarr[j+1];
            }
            size=size-1;
            i=pos;
        }
    }
}
int main()
{
    FILE *file = fopen("test.txt","r");
    char array[MAX_SIZE];
    int len=0;
    while(len<MAX_SIZE && fscanf(file,"%c",&array[len])==1)
    {
        len++;
    }
    fclose(file);
    int code[len];
    changetoint(len, array, code);
    int count=countoffiveones(len,code);
    int decryptdata_size=len-count;
    decryptdata(decryptdata_size,code);
    file=fopen("test.txt","a");
    fprintf(file,"\nthe decrypted data : ");
    for(int i=0;i<decryptdata_size;i++)
    {
        fprintf(file,"%d",code[i]);
    }
    fclose(file);
    return 0;
}
