#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,sum = 0;


    while(sum < 100)
    {
        printf("\n Sum now is : %d  Enter A number too add: ",sum);
        scanf("%d",&num);
        if(sum+num >=100)
        {
            printf("\n%d plus %d is bigger than hundred so the final sum is : %d",sum,num,sum);
            break;
        }
        sum+=num;
    }
    return 0;
}
