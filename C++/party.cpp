#include <bits/stdc++.h>
#define INF (1<<30)
using namespace std;

struct info{
	int x,y;
	info(){}
	info(int a,int b){x=a,y=b;}
};
int n,m,X;
vector<info> road[1005];
int spfa(int _start,int _end){
	int inQ[1005],dist[1005];
	queue<int> Q;
	for(int i=1;i<=n;i++){
		inQ[i] = 0;
		dist[i] = INF;
	}
	Q.push(_start);
	inQ[_start] = 1;
	dist[_start] = 0;
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		inQ[cur] = 0;
		for(auto i:road[cur]){
			if(dist[i.x] > dist[cur] + i.y){
				dist[i.x] = dist[cur] + i.y;
				if(!inQ[i.x]){
					Q.push(i.x);
					inQ[i.x] = 1;
				}
			}
		}
	}
	return dist[_end];
}
int main()
{
	scanf("%d %d %d",&n,&m,&X);
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		road[a].push_back(info(b,c));
	}
	int res = 0;
	for(int i=1;i<=n;i++){
		if(i == X) continue;
		res = max(res,spfa(X,i)+spfa(i,X));
	}
	printf("%d",res);
}