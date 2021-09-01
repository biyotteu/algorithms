#include <bits/stdc++.h>
#define INF (1<<30);

using namespace std;

int road[1005][1005],DP[1005][1005];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				char c;
				scanf(" %c",&c);
				if(c == '.') road[i][j] = 0;
				else road[i][j] = c - 48;
				DP[i][j] = INF;
			}
		DP[0][0] = 0;
		
	}
}