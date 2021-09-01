#include <bits/stdc++.h>
#define INF (1<<29)

using namespace std;

struct info{
	int x,y;
	info(){}
	info(int a,int b){
		x = a, y = b;
	}
};
vector<info> cum[10005];
int n,d,c;
void spfa(){
	vector<int> dist,inQ,check;
	queue<int> Q;
	int cnt = 0;
	dist.resize(n+1,INF);
	inQ.resize(n+1,0);
	check.resize(n+1,0);
	dist[c] = 0;
	inQ[c] = 1;
	Q.push(c);
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		inQ[cur] = 0;
		for(auto i:cum[cur]){
			if(dist[i.x] > dist[cur] + i.y){
				if(!check[i.x]){
					check[i.x] = 1;
					cnt++;
				}
				dist[i.x] = dist[cur] + i.y;
				if(!inQ[i.x]){
					inQ[i.x] = 1;
					Q.push(i.x);
				}
			}
		}
	}
	int MAX = 0;
	for(int i=1;i<=n;i++) if(dist[i] != INF) MAX = max(dist[i],MAX);
	printf("%d %d\n",cnt,MAX);
	return;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n,&d,&c);
		for(int i=0;i<d;i++){
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			cum[y].push_back(info(x,z));
		}
		spfa();
		for(int i=1;i<=n;i++) cum[i].clear();
	}
}
