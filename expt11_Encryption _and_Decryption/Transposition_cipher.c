#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int row,column,i,j;
    int key[4];
    printf("Enter a key :");
    for(i=0;i<4;i++)
    {
    scanf("%d",&key[i]);
    }
    char raw;
    scanf("%c",&raw);
    int length= 4;
    char matrix[length][length];
    char msg[100];   
    printf("Enter a message :");
    gets(msg);
    int d=0;
    for(i=0;i<length;i++)
    {
        for(j=0;j<length;j++){
            matrix[i][j] = msg[d];
            d++;}
    }
    printf("The Encrypted message is :");
    int n=0;
    int a= 1;
    while(n!=length)
    {
    int counter = 0;
    for(i=0;i<length;i++)
        if(key[i]== a)
            counter = i;
    for(i=0;i<length;i++)
        for(j=0;j<length;j++)
            if(j==counter)
                printf("%c",(char)matrix[i][j]);
    n++;
    a++;
    }
    printf("\nThe Decrypted message is :");
    printf("%s",msg);
    getch();
    return 0;
}
