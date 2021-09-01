#include <stdio.h>

int main()
{
    int i,j,w,n, m, k;
  int a[100][100]={0,}, b[100][100]={0,}, c[100][100]={0,};
  scanf("%d %d", &n, &m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d ", &a[i][j]);
        }
    }
    scanf("%d %d", &m, &k);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=k;j++)
        {
            scanf("%d ", &b[i][j]);
        }
    }
    for(i=1; i<=n;i++)
    {
        for(j=1; j<=k;j++)
        {
            for(w=1; w<=m; w++)
            {c[i][j] += a[i][w]*b[w][j];
            }
        }
    }
    for(i=1; i<=n;i++)
    {
        for(j=1; j<=k;j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}