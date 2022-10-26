#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

struct Employee
{
    int ID;
    int Age;
    char Gender;
    char Name[10];
    char Address[10];
    int Salary;
    int overTime;
    int Deduction;
};


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

int main()
{
    ///ID Name Age Gender Address Salary Overtime Deduction
    struct Employee e;
    int net;
    gotoxy(50,0);
    printf("Employee Data");

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
    scanf("%d",&e.ID);

    gotoxy(15,10);
    scanf("%s",&e.Address);

    gotoxy(15,15);
    scanf("%d",&e.Age);

    gotoxy(15,20);
    scanf("%s",&e.Gender);

    gotoxy(15,25);
    scanf("%s",&e.Name);

    gotoxy(70,5);
    scanf("%d",&e.Salary);

    gotoxy(70,10);
    scanf("%d",&e.overTime);

    gotoxy(70,15);
    scanf("%d",&e.Deduction);

    net= e.Salary + e.overTime - e.Deduction;
    gotoxy(0,30);
    printf("ID %i Name %s  Address %s Net Salary %d", e.ID, e.Name, e.Address,net);


    return 0;
}
