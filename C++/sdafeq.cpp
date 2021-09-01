#include <stdio.h>

void input_std_name(char (*name)[10])
{
    int i;
    for(i=0; i<3; i++)
    {
        printf("%d name: ", i+1);
        scanf(" %s", name[i]);
    }
}

void input_score(char (*name)[10], int (*score)[5])
{
    int i, j;
    for(i=0; i<3; i++)
    {
        printf("name %s ", name[i]);
        for(j=0; j<5; j++)
            scanf("%d", &score[i][j]);
    }
}

void average(int std_score[3][5], float *std_avg)
{
    for(int i = 0; i<3; i++)
    {
        int avg=0;
        for (int j=0; j<5; j++)
        {
            avg += std_score[i][j];
        }
        avg = avg/5;
        std_avg[i] = avg;
    }
}

void grad(float std_avg[3], char (*std_grad))
{
    int i;
    for(i=0; i<3; i++)
    {

        switch((int)(std_avg[i]/))
        {
            case 100: break;
            case 90: std_grad[i] = 'A'; break;
            case 80: std_grad[i] = 'E'; break;
            case 70: std_grad[i] = 'C'; break;
            case 60: std_grad[i] = 'D'; break;
            default: std_grad[i] = 'F';
        }
    }
}

void output_data(char name[3][10], int std_score[3][5], float std_avg[5], char std_grad[5])
{
    int i, j;
    for(i=0; i<3; i++)
    {
        printf("이름 : %s\n", name[i]);
        printf("국 영 수 사 과\n");
        for(j=0; j<5; j++)
        {
            printf("%d ", std_score[i][j]);
        }
        printf("\n과목 평균 : %g\n", std_avg[i]);
        printf("성적 : %c", std_grad[i]);
        printf("\n\n");
    }
}

int main()
{
    int i, total_sub_avg;
    char std_name[3][10], std_grad[5];
    int std_score[3][5];
    float std_avg[5];

    input_std_name(std_name);
    input_score(std_name, std_score);
    average(std_score, std_avg);
    grad(std_avg,std_grad);
    output_data(std_name, std_score, std_avg, std_grad);
}