#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<windows.h>

#define NormalPen 0x0F
#define HighLightPen 0XF0
#define Enter 0x0D
#define ESC 27
#define Size 3


typedef struct Employee
{
    int ID;
    int Age;
    char Gender;
    char Name[10];
    char Address[10];
    int Salary;
    int overTime;
    int Deduction;
} Employee;

Employee e[Size];


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

void enter_employees_new_data()
{
    system("cls");
    ///ID Name Age Gender Address Salary Overtime Deduction
    int i;
    for(i = 0 ; i < Size ; i++)
    {
        gotoxy(40,0);
        printf("Enter Employee Number %i Data",i+1);

        ///OutPuts
        gotoxy(5,5);
        printf("ID:");

        gotoxy(5,10);
        printf("Address:");

        gotoxy(5,15);
        printf("Age:");

        gotoxy(5,20);
        printf("Gender:");

        gotoxy(5,25);
        printf("Name:");

        gotoxy(60,5);
        printf("Salary:");

        gotoxy(60,10);
        printf("Overtime:");

        gotoxy(60,15);
        printf("Deduction:");


        ///Inputs
        gotoxy(15,5);
        scanf("%d",&e[i].ID);

        gotoxy(15,10);
        scanf("%s",&e[i].Address);

        gotoxy(15,15);
        scanf("%d",&e[i].Age);

        gotoxy(15,20);
        scanf("%s",&e[i].Gender);

        gotoxy(15,25);
        scanf("%s",&e[i].Name);

        gotoxy(70,5);
        scanf("%d",&e[i].Salary);

        gotoxy(70,10);
        scanf("%d",&e[i].overTime);

        gotoxy(70,15);
        scanf("%d",&e[i].Deduction);
        system("cls");

    }
    gotoxy(0,3);
    printf("Press Any Key to return to Home Screen!");
    _getch();

}

void display_employees_data()
{
    system("cls");
    int i;
    gotoxy(50,0);
    printf("Employees Data!");
    gotoxy(0,5);
    for(i = 0 ; i < Size ; i++ )
    {
        printf("%i. ID: %d Name: %s Net-Salary %d\n",i+1,e[i].ID,e[i].Name, e[i].Salary + e[i].overTime - e[i].Deduction);
    }
    gotoxy(0,3);
    printf("Press Any Key to return to Home Screen!");
    _getch();
}


int main()
{
    char menu[3][8] = {"New ","Display","Exit"};
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
                enter_employees_new_data();
                break;
            case 1:///display
                display_employees_data();
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
