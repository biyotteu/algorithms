#include <bits/stdc++.h>

using namespace std;

int n,m;
long long gr[105][105];
int main(){
	scanf("%d %d",&n,&m);
	while(m--){
		long long int x,y,z;
		scanf("%lld %lld %lld",&x,&y,&z);
		if(!gr[x][y]) gr[x][y] = z;
		else gr[x][y] = min(gr[x][y],z);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(i == j || gr[i][k] == 0 || gr[k][j] == 0) continue;
				if(gr[i][j] == 0 || gr[i][j] > gr[i][k] + gr[k][j])
					gr[i][j] = gr[i][k] + gr[k][j];
			}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%lld ",gr[i][j]);
		printf("\n");
	}
}