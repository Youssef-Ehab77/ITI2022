#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle( STD_OUTPUT_HANDLE ),
        coord
    );
}

void main()
{
    int i ;
    int size ;
    int row =1;
    int col;
    printf("please enter your limit :");
    scanf("%d \n",&size);

    col = (size/2)+1;

    if(size%2 == 1)
    {

        for( i=1 ; i<=(size*size); i++)
        {
            gotoxy(col*3,row*3);
            printf("%d",i);

            if(i%size==0)
            {
                row++;
                if(row>size);
                {
                    row= 1;
                }

            }
            else
            {
                row--;
                col-- ;

                if(row < 1 )
                    row = size ;

                if( col < 1 )
                    col=size;
            }
        }
    }
    else
    {
        printf("please enter another number");
    }
}






