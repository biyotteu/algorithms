#include<stdio.h>

int a;
int height[500005];
int loc[500005];
int n,c,j;

int main(){

    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        while(height[j]<a&&j>0) j--;
        printf("%d ",loc[j]);
        height[++j]=a;
        loc[j]=i;
    }
}
