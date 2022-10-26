#include <stdio.h>
#include <stdlib.h>


void swap_by_value(int x , int y){
    int temp = x;
    x = y;
    y = temp;
}

void swap_by_refrence(int*x, int*y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int x = 5 , y = 7;
    swap_by_value(x,y);//value does not change
    printf("X= %d , Y= %d\n",x,y);
    swap_by_refrence(&x,&y); //value changes
    printf("X= %d , Y= %d\n",x,y);
    return 0;
}
