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

Employee e;

char* line_editior(int xPos, int yPos, int asciiS, int asciiE)
{
    int x = xPos, y = yPos, endX = xPos;//x and y for current ptr , endX is x position for end ptr
    //char line[10]; //works only with char[] and strings does not work with int and double !!?!?!?!?!?
    char *line = (char*) calloc(10,sizeof(char));//dynamic memory allocation works with both???
    char *current,*start, *end;
    current = start = end = line;
    char ch;
    int exit = -1;
    while(exit == -1)
    {
        ch = getch();
        switch (ch)
        {
        case Enter:
            exit = 1;
            *end='\0';
            break;
        case -32:
            ch = _getch();
            switch (ch)
            {
            case 71:///home
                current = line;
                gotoxy(xPos,yPos);
                break;
            case 97:///end
                current = end;
                gotoxy(endX,y);
                break;
            case 75:///left
                if(current > start)
                {
                    current--;
                    gotoxy(--x,y);
                }
                break;
            case 77:///right
                if(current < end)
                {
                    current++;
                    gotoxy(++x,y);
                }
                break;
            }
            break;
        default:
            ///make sure to print only values between the range sent to the function( nums or letters)
            if(ch >= asciiS && ch <= asciiE)
            {
                if(current < start+8)
                {
                    *current = ch;
                    gotoxy(x++,y);
                    printf("%c",ch);
                    current++;
                    if(end < start+8 && current == end+1){
                        end++;
                        endX++;
                    }
                }
            }
        }
    }
    return line;
}

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

    gotoxy(40,0);
    printf("Enter Employee Data");

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
    ///id
    gotoxy(15,5);
    e.ID = atoi(line_editior(15,5,48,57));
    ///address
    gotoxy(15,10);
    strcpy(e.Address, line_editior(15,10,97,122));
    ///age
    gotoxy(15,15);
    e.Age = atoi(line_editior(15,15,48,57));
    ///gender
    gotoxy(15,20);
    e.Gender = line_editior(15,20,97,122);
    ///name
    gotoxy(15,25);
    strcpy(e.Name,line_editior(15,25,97,122));
    ///salary
    gotoxy(70,5);
    e.Salary = atoi(line_editior(70,5,48,57));
    ///overtime
    gotoxy(70,10);
    e.overTime = atoi(line_editior(70,10,48,57));
    ///deduction
    gotoxy(70,15);
    e.Deduction = atoi(line_editior(70,15,48,57));
    system("cls");

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
    printf("ID: %d\nName: %s\nNet-Salary: %d\nAddress: %s\nAge: %d\n",e.ID,e.Name, e.Salary + e.overTime - e.Deduction,e.Address,e.Age);
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
