#include <stdio.h>
#include <string.h>
int a[101],n;
int main()
{
    int cnt=0,i, sizea, aa=0;
    scanf("%d", &n);
    while(cnt<n)
    {
        char b[10], c;
        scanf("%s", &b);
        if(!strcmp(b, "create"))
        {
            scanf("%d", &c);
            sizea=c;
        }
        else if(!strcmp(b, "pop"))
        {
            if(aa==0)
                printf("underflow\n");
            else{
                aa--;
                a[aa]=0;
 
                for(i=0;i<sizea;i++)
                    printf("%d ", a[i]);
                printf("\n");
            }
        }
        else if(!strcmp(b, "push"))
        {
            scanf("%d", &c);
            if(sizea==aa)
                printf("overflow\n");
            else{
                a[aa]=c;
                aa++;
                for(i=0;i<sizea;i++)
                    printf("%d ", a[i]);
                printf("\n");
        }
        }
        else if(!strcmp(b, "double"))
        {
            sizea*=2;
            if(sizea>100)
                sizea=100;
        }
        cnt++;
    }
    return 0;
}