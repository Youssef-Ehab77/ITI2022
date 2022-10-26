#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    int isAscii;
    do
    {
        isAscii = 0;
        ch = getch();
        if( ch == -32){
            ch = getch();
            isAscii = 1;
        }
        printf("%d is %d\n",isAscii,ch);
    }
    while(ch != 'x');
    return 0;
}
