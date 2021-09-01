#include <bits/stdc++.h>
#define INF (1<<29)

using namespace std;

int n,End,dist[20][20],dp[20][1<<20];
int f(int v,int check){
	if(check == End)	return dist[v][1];
	int &ret = dp[v][check]; 
	if(ret) return ret;
	ret = INF;
	for(int i=2;i<=n;i++){
		if((check&(1<<i)) == 0 && dist[v][i] != INF)
			ret = min(ret,f(i,(check|(1<<i)))+dist[v][i]);
	}
	return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		End |= (1<<i);
		for(int j=1;j<=n;j++){
			scanf("%d",&dist[i][j]);
			if(!dist[i][j]) dist[i][j] = INF;
		}
	}
	printf("%d",f(1,2));
}	