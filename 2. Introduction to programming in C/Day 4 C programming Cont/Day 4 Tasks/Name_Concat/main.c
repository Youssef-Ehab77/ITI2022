#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    char lastName[10];

    printf("Please Enter First Name: ");
    scanf("%s",&name);

    printf("Please Enter Second Name: ");
    scanf("%s",&lastName);
    _flushall();

    strcat(name," ");
    strcat(name,lastName);
    puts(name);
    //printf("Full name is : %s",name);

    return 0;
}
