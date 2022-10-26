#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<windows.h>

#define NormalPen 0x0F
#define HighLightPen 0XF0
#define Enter 0x0D
#define ESC 27


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

void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}



int main()
{
    char menu[3][5] = {"New ","Save","Exit"};
    int i, current = 0, ExitFlag = 0;
    char ch;


    do
    {

        textattr(NormalPen);
        system("cls");

        for(i = 0 ; i<3; i++)
        {
            if(current == i)
                textattr(HighLightPen);
            else textattr(NormalPen);

            gotoxy(20,10+(3*i));
            printf("%s",menu[i]);
        }

        ch = _getch();

        switch (ch)
        {
        case Enter:
            switch (current)
            {
            case 0:///new
                system("cls");
                printf("You Are In New Page!");
                _getch();
                break;
            case 1:///save
                system("cls");
                printf("You Are In Save Page!");
                break;
            case 2:///exit
                ExitFlag = 1;
                break;
            }
            break;
        case ESC:
            ExitFlag = 1;
            break;
        case -32:
            ch = _getch();
            switch (ch)
            {
            case 72:///up
                current--;
                if(current<0) current = 2;
                break;
            case 80:///down
                current++;
                if(current>2) current =0;
                break;
            case 71:///home
                current = 0;
                break;
            case 79:
                current = 2;
                break;
            }
        }
    }
    while(!ExitFlag==1);




    return 0;
}
