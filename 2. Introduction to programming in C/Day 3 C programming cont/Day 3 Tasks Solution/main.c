#include <stdio.h>
#include <limits.h>
#include "stdlib.h"

///1) Input and output an array using 2 for loops.
void task1()
{
    int i;
    int array[10];

    for ( i = 0; i < 10; ++i)
    {
        printf("Enter the element number %d:\n", i + 1);
        scanf("%d", &array[i]);
    }

    printf("The Array Elements --> \n");

    for ( i = 0; i < 10; ++i)
    {
        printf("%d. %d\n", i + 1, array[i]);
    }
}

///2) Get Minimum and Maximum value of an array.
void task2()
{
    int array[10] = {12, 432, 44, 1, 776, 453, 19329, 4311, 6, 547};
    int max = INT_MIN, min = INT_MAX;
    int i;

    for ( i = 0; i < 10; ++i)
    {
        if (array[i] > max)
            max = array[i];
        if (array[i] < min)
            min = array[i];
    }
    printf("Maximum Number is : %d \nMinimum Number is: %d", max, min);

}

///3) Calculate sum of each row in a 2D Array.
///4) Bonus: Calculate average of each column in a 2D Array.
void task_3_and_bonus()
{
    //sum: 14,30,46  avg:(18/3)=6 , (21/3)=7 , (24/3)=8 , (27/3)=9
    int arr[3][4] = {{2,  3,  4,  5},
        {6,  7,  8,  9},
        {10, 11, 12, 13}
    };
    int sum[3] = {0};
    int avg[4] = {0};
    int i, j;

    for ( i = 0; i < 3; ++i)
    {
        for ( j = 0; j < 4; ++j)
        {
            sum[i] += arr[i][j];
            avg[j] += arr[i][j];
        }
    }

    for ( i = 0; i < 3; ++i)
    {
        printf("Sum of row number %d is : %d\n", i + 1, sum[i]);
    }

    for ( i = 0; i < 4; ++i)
    {
        printf("Average of column number %d is : %d\n", i + 1, avg[i] / 3);
    }

}

///5) Multiply two matrix 3x2 , 2x1 --> 3x1
void task5()
{
    int a1[3][2] = {{1, 2},
        {2, 3},
        {3, 4}
    };
    int a2[2][1] = {{1},
        {2}
    };
    int output[3] = {0};
    int i, j;

    for ( i = 0; i < 3; ++i)
    {
        for ( j = 0; j < 2; ++j)
        {
            output[i] += a1[i][j] * a2[j][i];
        }
    }
    printf("**************The Output 3x1 Matrix**********\n");
    for ( i = 0; i < 3; ++i)
    {
        printf("%d\n", output[i]);
    }

}

///6) number of rows and cols from users Must(NxM , MxK)--> NxK
void task6()
{
    int r1, c1, r2, c2, i, j, x;
    printf("Please Enter numbers of row of the 1st matrix: ");
    scanf("%d", &r1);
    printf("Please Enter numbers of columns of the 1st matrix: ");
    scanf("%d", &c1);
    printf("Please Enter numbers of rows of the 2nd matrix: ");
    scanf("%d", &r2);
    printf("Please Enter numbers of columns of the 2nd matrix: ");
    scanf("%d", &c2);

    if (c1 != r2)
    {
        printf("Column in matrix 1 not equal row of column 2");
        exit(0);
    }
    else
    {
        int matrix1[r1][c1];
        int matrix2[r2][c2];
        int output[r1][c2];

        printf("********** MATRIX 1 *********** \n");
        for (i = 0; i < r1; ++i)
        {
            for (j = 0; j < c1; ++j)
            {
                printf("Enter the element in (%d , %d) : \n", i, j);
                scanf("%d", &matrix1[i][j]);
            }
        }

        printf("********** MATRIX 2 *********** \n");
        for (i = 0; i < r2; ++i)
        {
            for (j = 0; j < c2; ++j)
            {
                printf("Enter the element in (%d , %d) : \n", i, j);
                scanf("%d", &matrix2[i][j]);
            }
        }

        ///zero the matrix
        for (i = 0; i < r1; ++i)
        {
            for (j = 0; j < c2; ++j)
            {
                output[i][j] = 0;
            }
        }

        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c2; j++)
            {
                for ( x = 0; x < c1; x++)
                {
                    output[i][j] += matrix1[i][x] * matrix2[x][j];
                }
            }
        }

        printf("***********The output Matrix **************\n");
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c2; j++)
            {
                printf("%d  ", output[i][j]);
            }
            printf("\n");
        }
    }
}

void task6_2for()
{
    int r1, c1, r2, c2, i, j, x;
    printf("Please Enter numbers of row of the 1st matrix: ");
    scanf("%d", &r1);
    printf("Please Enter numbers of columns of the 1st matrix: ");
    scanf("%d", &c1);
    printf("Please Enter numbers of rows of the 2nd matrix: ");
    scanf("%d", &r2);
    printf("Please Enter numbers of columns of the 2nd matrix: ");
    scanf("%d", &c2);

    if (c1 != r2)
    {
        printf("Column in matrix 1 not equal row of column 2");
        exit(0);
    }
    else
    {
        int matrix1[r1][c1];
        int matrix2[r2][c2];
        int output[r1][c2];

        printf("********** MATRIX 1 *********** \n");
        for (i = 0; i < r1; ++i)
        {
            for (j = 0; j < c1; ++j)
            {
                printf("Enter the element in (%d , %d) : \n", i, j);
                scanf("%d", &matrix1[i][j]);
            }
        }

        printf("********** MATRIX 2 *********** \n");
        for (i = 0; i < r2; ++i)
        {
            for (j = 0; j < c2; ++j)
            {
                printf("Enter the element in (%d , %d) : \n", i, j);
                scanf("%d", &matrix2[i][j]);
            }
        }

        ///zero the matrix
        for (i = 0; i < r1; ++i)
        {
            for (j = 0; j < c2; ++j)
            {
                output[i][j] = 0;
            }
        }

        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c2; j++)
            {
                for ( x = 0; x < c1; x++)
                {
                    output[i][j] += matrix1[i][x] * matrix2[x][j];
                }
            }
        }

        printf("***********The output Matrix **************\n");
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c2; j++)
            {
                printf("%d  ", output[i][j]);
            }
            printf("\n");
        }
    }
}


int main()
{

    //task1();
    //task2();
    //task_3_and_bonus();
    //task5();
    task6();
    //task6_2for();
    return 0;
}
