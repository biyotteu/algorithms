#include<stdio.h>

int score[1001];
int st[1001];
int d[1010];
int main()
{
	int n,m;
	char a[2];
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++) scanf("%d",&score[i]);
	for(int i=1; i<=m; i++){
		scanf("%d",&st[i]);
		for(int j=1; j<=n; j++){
			scanf("%s",a);
			if(a[0] == 'O'){
				d[i]=d[i]+score[j];
			}
		}
	}
	int num,max=0;
	for(int i=1; i<=m; i++){
		if(d[i] > max){
			max=d[i];
			num=st[i];
		}
		if(d[i] == max){
			if(st[i] < num){
				max=d[i];
				num=st[i];
			}
		}
	}
	printf("%d %d",num,max);
	return 0;
}