#include<stdio.h>
int main()
{
    int c, n,b=0;
    double avg_1, rate,sum_1=0,score1[1000],score[1000];

    scanf("%d",&c);

    for(int i=0;i<c;i++)
    {
        scanf("%d", &n);
        sum_1 = 0;
        b = 0;
        for(int j=0;j<n;j++)
        {
            scanf("%lf", &score[j]);
            sum_1 = sum_1 + score[j];
        }
        avg_1 = sum_1 / (double)n;
        for(int j=0;j<n;j++)
        {
            if(score[j] > avg_1){
            	b++;
            }
        }
        rate = ((double)b/n) *100;
        printf("%.3lf%\n", rate);
    }

}