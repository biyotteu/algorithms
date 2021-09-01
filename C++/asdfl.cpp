#include <stdio.h>
#include <limits.h>

int main(void)
{
    int i, max, min, j;
    scanf("%d", &i);
    max = -INT_MAX;
    min = INT_MAX;
    for(j=0; j<i; j++)
    {
        int x;
        scanf("%d", &x);
        if(x > max)
        {
            max = x;
        }
        if(x < min)
        {
            min = x;
        }
    }
    printf("%d %d", min, max);
    return 0;
}