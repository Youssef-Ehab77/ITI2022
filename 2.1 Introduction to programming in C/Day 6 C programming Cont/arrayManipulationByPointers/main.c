#include <stdio.h>
#include <stdlib.h>

int main()
{

    int arr[5] , i ;
    int* ptr = arr;

    for(i = 0 ; i < 5 ; i++){
        printf("Enter a number : ");
        scanf("%d",(ptr+i));
    }

    for(i = 0 ; i < 5 ; i++){
        printf("Element %d is : %d\n",i+1, *(ptr+i));
    }
    return 0;
}
