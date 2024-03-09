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
int encryptdata(int totalsize, int encryptarr[])
{
    for(int i=0;i<totalsize;i++)
    {
        int pos=0;
        if(encryptarr[i]==1 && encryptarr[i+1]==1&& encryptarr[i+2]==1&&encryptarr[i+3]==1&&encryptarr[i+4]==1)
        {
            pos=i+5;
            for(int j=totalsize;j>=pos;j--)
            {
                encryptarr[j]=encryptarr[j-1];
            }
            encryptarr[pos]=0;
            i=pos;
        }
    }
}
int main()
{
    FILE *file = fopen("bit_stuff.txt","r");
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
    int encryptdata_size= len+count;
    code[encryptdata_size];
    encryptdata(encryptdata_size,code);
    file=fopen("bit_stuff.txt","a");
    fprintf(file,"\nthe encrypted data : ");
    for(int i=0;i<len+count;i++)
    {
        fprintf(file,"%d",code[i]);
    }
    fclose(file);
    return 0;
}
