#include <stdio.h>
#include <stdlib.h>

#define Enter 0x0D

int main()
{
    char name[20];

    printf("Please Enter Your Name : ");
    gets(name);

    printf("Welcome ");
    puts(name);

    return 0;
}


/*

 char name[10];
    char ch;
    int index = 0;

   while((ch = getchar()) != '\n'){
     name[index++] = ch;
   }

    printf("%s",name); */
