#include <stdio.h>
#include <string.h>
int main()
{
    int n,i,j;
    char str[100];
    char en_str[100];
    char de_str[100];
    char raw;
    printf("Enter the key :");
    scanf("%d",&n);
    scanf("%c",&raw);
    printf("Enter message :");
    gets(str);
    printf("The Encrypted message :");
    for(i=0;i<strlen(str);i++)
    {
        en_str[i]=str[i]+n;
    }
    printf("%s",en_str);
    printf("\nThe Retrived message is :");
    for(i=0;i<strlen(str);i++)
    {
        de_str[i]=en_str[i]-n;
    }
    printf("%s",de_str);
}