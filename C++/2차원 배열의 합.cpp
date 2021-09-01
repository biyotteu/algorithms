#include <bits/stdc++.h>

using namespace std;

int sum[305][305];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int x;
			scanf("%d",&x);
			sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + x;
		}
	int T;
	scanf("%d",&T);
	while(T--){
		int x1,x2,y1,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		printf("%d\n",sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1]);
	}
}