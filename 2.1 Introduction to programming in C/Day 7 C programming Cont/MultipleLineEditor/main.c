#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<windows.h>

#define NormalPen 0x0F
#define HighLightPen 0X90
#define Enter 0x0D
#define ESC 27
#define Size 3


typedef struct Employee
{
    int ID;
    int Age;
    char Gender;
    char Name[10];
    char Address[15];
    int Salary;
    int overTime;
    int Deduction;
} Employee;


void gotoxy(int column, int line);
void textattr(int i);
void enter_employees_new_data(Employee*);
char** multi_line_editor(int numberOfLines, int *maxLineLength, int *xPos, int *yPos, int *Schar, int *Echar);
void display_employee_data_by_id(Employee*);
void display_all_employee_data(Employee*);
void delete_employee_by_id(Employee*);
void delete_employee_by_name(Employee*);

int main()
{
    char menu[6][20] = {" New ","Display by ID","Display All","Delete by ID","Delete by Name","Exit"};
    int i, current = 0, ExitFlag = 0;
    char ch;
    Employee *e = (Employee*)calloc(10,sizeof(Employee));

    do
    {
        textattr(NormalPen);
        system("cls");

        for(i = 0 ; i<6; i++)
        {
            if(current == i)
                textattr(HighLightPen);
            else textattr(NormalPen);

            gotoxy(50,10+(3*i));
            printf("%s",menu[i]);
        }

        ch = _getch();

        switch (ch)
        {
        case Enter:
            switch (current)
            {
            case 0:///new by index
                enter_employees_new_data(e);
                break;
            case 1:///display by id
                display_employee_data_by_id(e);
                break;
            case 2:///display all
                display_all_employee_data(e);
                break;
            case 3:///delete by id
                delete_employee_by_id(e);
                break;
            case 4:///delete by name
                delete_employee_by_name(e);
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
                if(current<0) current = 5;
                break;
            case 80:///down
                current++;
                if(current>5) current =0;
                break;
            case 71:///home
                current = 0;
                break;
            case 79:
                current = 5;
                break;
            }
        }
    }
    while(!ExitFlag==1);

    free(e);
    return 0;
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

void enter_employees_new_data(Employee* e)
{
    ///ID Address Age Gender Name Salary Overtime Deduction
    /// 48, 57 numbers 97, 122 letters
    int index,i;
    char ch = '\0';

    system("cls");
    printf("Please Enter Index you want to add in: ");
    scanf("%d",&index);
    if(e[index].ID != 0)
    {
        printf("There is an employee at index %d!\n",index);
        printf("Press any key to return...");
        _getch();
    }
    else
    {
        system("cls");
        int numberOfLines = 8;
        int xPos[8] = {15,15,15,15,15,70,70,70};
        int yPos[8] = {5,10,15,20,25,5,10,15};
        int Schar[8] = {48,97,48,97,97,48,48,48};
        int Echar[8] = {57,122,57,122,122,57,57,57};
        int maxLineLength[8] = {5,15,3,2,10,5,5,5};

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

        gotoxy(15,5);
        char **data = multi_line_editor(numberOfLines,maxLineLength,xPos,yPos,Schar,Echar);
        system("cls");
        gotoxy(0,3);
        printf("Press Any Key to return to Home Screen!");
        _getch();

        e[index].ID = atoi(data[0]);
        strcpy(e[index].Address,data[1]);
        e[index].Age = atoi(data[2]);
        e[index].Gender = data[3][0];
        strcpy(e[index].Name,data[4]);
        e[index].Salary = atoi(data[5]);
        e[index].overTime = atoi(data[6]);
        e[index].Deduction = atoi(data[7]);

        for(i = 0 ; i < numberOfLines ; i++)
            free(data[i]);
        free(data);

    }
}

void display_all_employee_data(Employee *e)
{
    system("cls");
    int i;
    gotoxy(50,0);
    printf("Employees Data!");
    gotoxy(0,5);
    for(i = 0 ; i <10; i++)
    {
        if(e[i].ID != 0)
        {
            printf("ID: %d |Name: %s |Gender: %c |Net-Salary: %d |Address: %s |Age: %d\n",e[i].ID,
                   e[i].Name,e[i].Gender, e[i].Salary + e[i].overTime - e[i].Deduction,e[i].Address,e[i].Age);
        }
    }
    gotoxy(0,3);
    printf("Press Any Key to return to Home Screen!");
    _getch();
}

char** multi_line_editor(int numberOfLines, int *maxLineLength, int *xPos, int *yPos, int *Schar, int *Echar)
{
    char **line = (char**) calloc(numberOfLines,sizeof(char*));
    char current[numberOfLines], end[numberOfLines];
    char ch;
    int exit = -1;
    int i,j;
    int currentLine = 0;

    for(i = 0; i < numberOfLines; i++)
    {
        line[i] = (char*) malloc(sizeof(char)*maxLineLength[i]);
    }

    for(i = 0; i < numberOfLines; i++)
    {
        current[i] = end[i] = 0;
    }

    ///Drawing the box for the inputs
    for (i = 0; i < numberOfLines; i++)
    {
        textattr(HighLightPen);
        for (j = 0; j < maxLineLength[i]; j++)
        {
            gotoxy(xPos[i] + j, yPos[i]);
            printf(" ");
        }

    }

    while(exit == -1)
    {
        gotoxy(xPos[currentLine]+current[currentLine], yPos[currentLine]);
        ch = getch();
        switch (ch)
        {
        case Enter:///enter
            for(i = 0; i < numberOfLines ; i++)
                line[i][end[i]]='\0';
            exit = 1;
            break;
        case 9:///tab
            if(currentLine < numberOfLines-1)
            {
                currentLine++;
            }
            else currentLine = 0;
            break;
        case -32:
            ch = _getch();
            switch (ch)
            {
            case 72:///up
                if(currentLine > 0)
                {
                    currentLine--;
                }
                else currentLine = 7;
                break;
            case 80:///down
                if(currentLine < numberOfLines-1)
                {
                    currentLine++;
                }
                else currentLine = 0;
                break;
            case 75:///left
                if(current[currentLine] > 0)
                {
                    current[currentLine]--;
                }
                break;
            case 77:///right
                if(current[currentLine] < end[currentLine])
                {
                    current[currentLine]++;
                }
                break;
            case 71:///home
                current[currentLine] = 0;
                break;
            case 79:///end
                current[currentLine] = end[currentLine];
                break;
            }
            break;
        default:
            ///make sure to print only values between the range sent to the function( nums or letters)
            if(ch >= Schar[currentLine] && ch <= Echar[currentLine] && current[currentLine] <= end[currentLine])
            {

                line[currentLine][current[currentLine]] = ch;
                printf("%c",ch);
                current[currentLine]++;
                if(end[currentLine] < maxLineLength[currentLine]-1 && current[currentLine] == end[currentLine]+1)
                {
                    end[currentLine]++;
                }
            }
        }
    }
    textattr(NormalPen);
    return line;
}

void display_employee_data_by_id(Employee *e)
{
    int id ,i ,found = -1;
    char ch = '\0';

    system("cls");
    printf("Please Enter Employee ID: ");
    scanf("%d",&id);
    system("cls");
    gotoxy(50,0);
    printf("Employee Data!");
    gotoxy(0,5);
    for(i = 0 ; i <10; i++)
    {
        if(e[i].ID == id)
        {
            printf("ID: %d |Name: %s |Gender: %c |Net-Salary: %d |Address: %s |Age: %d\n",e[i].ID, e[i].Name,e[i].Gender, e[i].Salary + e[i].overTime - e[i].Deduction,e[i].Address,e[i].Age);
            found = 1;
            break;
        }
    }
    if(found == -1)
    {
        system("cls");
        printf("There is no Employee with ID %d",id);

    }
    gotoxy(0,3);
    printf("Press Any Key to return to Home Screen!");
    _getch();
}

void delete_employee_by_id(Employee *e)
{
    int id ,i ,found = -1;
    char ch = '\0';

    system("cls");
    printf("Please Enter Employee ID: ");
    scanf("%d",&id);
    gotoxy(0,5);
    for(i = 0 ; i <10; i++)
    {
        if(e[i].ID == id)
        {
            printf("Employee with ID %d delete successfully!\n",id);
            e[i].ID = 0;
            e[i].Name[0] = '\0';
            e[i].Gender = '\0';
            e[i].Salary = 0;
            e[i].overTime = 0;
            e[i].Deduction = 0;
            e[i].Address[0] = '\0';
            e[i].Age = 0;
            found = 1;
            break;
        }
    }
    if(found == -1)
    {
        system("cls");
        printf("There is no Employee with ID %d",id);

    }
    gotoxy(0,3);
    printf("Press Any Key to return to Home Screen!");
    _getch();
}

void delete_employee_by_name(Employee *e)
{
    int i ,found = -1;
    char ch = '\0';
    char name[10];

    system("cls");
    printf("Please Enter Employee Name: ");
    scanf("%s",name);
    gotoxy(0,5);
    for(i = 0 ; i <10; i++)
    {
        if(!strcmp(e[i].Name,name))
        {
            printf("Employee with Name %s delete successfully!\n",name);
            e[i].ID = 0;
            e[i].Name[0] = '\0';
            e[i].Gender = '\0';
            e[i].Salary = 0;
            e[i].overTime = 0;
            e[i].Deduction = 0;
            e[i].Address[0] = '\0';
            e[i].Age = 0;
            found = 1;
            break;
        }
    }
    if(found == -1)
    {
        system("cls");
        printf("There is no Employee with name %s",name);

    }
    gotoxy(0,3);
    printf("Press Any Key to return to Home Screen!");
    _getch();

}
