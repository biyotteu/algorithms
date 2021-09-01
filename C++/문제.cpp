#include <bits/stdc++.h>

using namespace std;

int n,m,visit[1000005],res;
char pro[1000005];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf(" %c",&pro[i]);
	for(int i=1;i<=m;i++){
		int y;
		char x;
		scanf(" %c %d",&x,&y);
		if(visit[y]) continue;
		if(pro[y]<=x){
			res++;
			visit[y] = 1;
		}
	}
	printf("%d",res);
}