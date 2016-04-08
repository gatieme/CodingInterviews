#include <stdio.h>
#include <stdlib.h>





int main(void)
{
    int N;
    int array[100];
    int sum = 0, big = 0, equal = 0;

    while(scanf("%d", &N) != EOF)
    {
        scanf("%d", &array[0]);
        sum = array[0];
        big = 0;
        equal = 0;
        for(int i = 1; i < N; i++)
        {
            scanf("%d", &array[i]);
            if(array[i] > array[0])
            {
                sum += array[i];
                big++;
            }
            else if(array[i] == array[0])
            {
                equal++;
            }
        }
        if(big > 0)
        {

            //printf("sum = %d, big = %d\n", sum, big);
            printf("%d\n", sum / (big + 1) + 1 - array[0]);
        }
        else if(big == 0 && equal > 0)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
}
