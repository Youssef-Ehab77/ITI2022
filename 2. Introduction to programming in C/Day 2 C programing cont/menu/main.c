#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    printf("Menu ---> \n 1. Burger \n 2. Chicken  \n 3. Kware3 \n");
    scanf("%d",&choice);

    switch(choice){

    case 1:
        printf("Your Choice is Burger!\n");
        break;
    case 2:
        printf("Your Choice is Chicken!\n");
        break;
    case 3:
        printf("Your Choice is Kware3!\n");
        break;
    default:
        printf("Wrong Choice!");

    }
    return 0;
}
