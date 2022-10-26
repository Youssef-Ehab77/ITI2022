#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **marks, stdN, subN, *sum, *avg, i, j;

    printf("Enter Number of students : \n");
    scanf("%d",&stdN);

    marks = (int**)calloc(stdN, sizeof(int*));
    sum = (int*)calloc(stdN,sizeof(int));

    printf("Enter number of subject: \n");
    scanf("%d",&subN);

    for(i = 0 ; i < stdN; i++)
    {
        marks[i] = (int*)calloc(subN,sizeof(int));
    }

    avg = (int*)calloc(subN,sizeof(int));

    for(i = 0 ; i < stdN; i++)
    {
        for(j = 0 ; j < subN; j++)
        {

            printf("Subject %i, Student %i\n",j+1,i+1);
            scanf("%i",&marks[i][j]);
            sum[i]+=marks[i][j];
            avg[j]+=marks[i][j];
        }
    }

    for(i = 0 ; i < subN; i++)
        avg[i] /= stdN;

    for(i = 0 ; i < subN; i++)
        printf("Average of subject %d is %d\n",i+1,avg[i]);

    for(i = 0 ; i < stdN; i++)
        printf("Student %d Sum of marks is %d\n",i+1,sum[i]);


    for(i = 0 ; i < stdN; i++)
        free(marks[i]);

    free(marks);
    free(sum);
    free(avg);



    return 0;
}
