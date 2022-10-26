#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<windows.h>

#define NormalPen 0x0F
#define HighLightPen 0X1A
#define Enter 0x0D
#define ESC 27
#define Size 10
#define options 6


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

void enter_employee_by_index()
{
    system("cls");
    ///ID Name Age Gender Address Salary Overtime Deduction
    int index;
    printf("Enter Index You want to add into: ");
    scanf("%d",&index);
    if(e[index].ID != 0)
    {
        printf("Index Already Filled with data!\n");
        printf("Press any key to continue...");
        _getch();
        return;
    }
    else
    {
        system("cls");
        gotoxy(50,0);
        printf("Enter Employee's Data");

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
        scanf("%d",&e[index].ID);

        gotoxy(15,10);
        scanf("%s",&e[index].Address);

        gotoxy(15,15);
        scanf("%d",&e[index].Age);

        gotoxy(15,20);
        scanf("%s",&e[index].Gender);

        gotoxy(15,25);
        scanf("%s",&e[index].Name);

        gotoxy(70,5);
        scanf("%d",&e[index].Salary);

        gotoxy(70,10);
        scanf("%d",&e[index].overTime);

        gotoxy(70,15);
        scanf("%d",&e[index].Deduction);
        system("cls");
        gotoxy(0,3);
        printf("Press Any Key to return to Home Screen!");
        _getch();

    }

}



void display_employee_by_id()
{
    system("cls");
    int id,i,current = -1;
    printf("Enter ID You want to display: ");
    scanf("%d",&id);
    for(i = 0 ; i < Size ; i++)
    {
        if(e[i].ID == id)
        {
            current = i;
            break;
        }
    }

    if(current == -1)
    {
        gotoxy(0,3);
        printf("ID Not Found!!\nPress Any Key to return to Home Screen!");
        _getch();
        return;
    }
    else
    {
        printf("  %i.|ID: %d | Name: %s | Net-Salary %d|\n",i,e[current].ID,e[current].Name,
               e[current].Salary + e[current].overTime - e[current].Deduction);
        printf("Press Any Key to return to Home Screen!");
        _getch();
        return;
    }

}

void display_all_employees_data()
{
    system("cls");
    int i;
    gotoxy(50,0);
    printf("Employees Data!");
    gotoxy(0,5);
    printf("Index  ID      Name      Salary\n");
    for(i = 0 ; i < Size ; i++ )
    {
        if(e[i].ID != 0)
        {
            printf("  %i.|ID: %d | Name: %s | Net-Salary %d|\n",i,e[i].ID,e[i].Name, e[i].Salary + e[i].overTime - e[i].Deduction);
        }
    }
    gotoxy(0,3);
    printf("Press Any Key to return to Home Screen!");
    _getch();
}

void delete_by_id()
{
    system("cls");
    int id,i,current = -1;
    printf("Enter ID You want to Delete: ");
    scanf("%d",&id);
    for(i = 0 ; i < Size ; i++)
    {
        if(e[i].ID == id)
        {
            current = i;
            break;
        }
    }

    if(current == -1)
    {
        gotoxy(0,3);
        printf("ID Not Found!!\nPress Any Key to return to Home Screen!");
        _getch();
        return;
    }
    else
    {
        e[current].ID = 0;
        e[current].Gender = '\0';
        e[current].Name[0] = '\0';
        e[current].Age = 0;
        e[current].Address[0]='\0';
        e[current].Salary = 0;
        e[current].overTime = 0;
        e[current].Deduction = 0;
        printf("Employee With ID %d deleted successfully!\n",id);
        printf("Press Any Key to return to Home Screen!");
        _getch();
        return;
    }
}

void delete_by_name()
{
    system("cls");
    char name[10];
    int i,current = -1;
    printf("Enter Name You want to Delete: ");
    scanf("%s",&name);
    for(i = 0 ; i < Size ; i++)
    {
        if(!strcmp(e[i].Name,name))
        {
            current = i;
            break;
        }
    }

    if(current == -1)
    {
        gotoxy(0,3);
        printf("Name Not Found!!\nPress Any Key to return to Home Screen!");
        _getch();
        return;
    }
    else
    {
        e[current].ID = 0;
        e[current].Gender = '\0';
        e[current].Name[0] = '\0';
        e[current].Age = 0;
        e[current].Address[0]='\0';
        e[current].Salary = 0;
        e[current].overTime = 0;
        e[current].Deduction = 0;
        printf("Employee With Name %s deleted successfully!\n",name);
        printf("Press Any Key to return to Home Screen!");
        _getch();
        return;
    }
}

int main()
{
    char menu[options][20] = {"New by Index","Display by ID","Display All","Delete by ID","Delete by Name","Exit"};
    int i, current = 0, ExitFlag = 0;
    char ch;


    do
    {
        textattr(NormalPen);
        system("cls");

        for(i = 0 ; i<options; i++)
        {
            if(current == i)
                textattr(HighLightPen);
            else textattr(NormalPen);

            gotoxy(50,5+(3*i));
            printf("%s",menu[i]);
        }

        ch = _getch();

        switch (ch)
        {
        case Enter:
            switch (current)
            {
            case 0:///new by index
                enter_employee_by_index();
                break;
            case 1:///display by id
                display_employee_by_id();
                break;
            case 2:///display all
                display_all_employees_data();
                break;
            case 3:///delete by id
                delete_by_id();
                break;
            case 4:///delete by name
                delete_by_name();
                break;
            case 5:///exit
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
                if(current<0) current = options-1;
                break;
            case 80:///down
                current++;
                if(current>options-1) current = 0;
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
