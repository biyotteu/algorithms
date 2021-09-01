#include <bits/stdc++.h>

using namespace std;

int n,m,dist[1000],inQ[1000],pr[1000];
int gr[1000][1000],able[1000][1000],cnt,res;
vector<int> edg[1000];
queue<int> Q;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		edg[0].push_back(i);
		edg[i].push_back(0);
		able[0][i] = 1;
		int x;
		scanf("%d",&x);
		for(int j=0;j<x;j++){
			int x,y;
			scanf("%d %d",&x,&y);
			able[i][x+n] = 1;
			edg[i].push_back(x+n);
			edg[x+n].push_back(i);
			gr[i][x+n] = y;
			gr[x+n][i] = -gr[i][x+n];
		}
	}
	for(int i=1;i<=m;i++){
		edg[i+n].push_back(n+m+1);
		edg[n+m+1].push_back(n+i);
		able[i+n][n+m+1] = 1;
	}
	while(1){
		memset(dist,-1,sizeof(dist));
		memset(inQ,0,sizeof(inQ));
		memset(pr,0,sizeof(pr));
		while(!Q.empty()) Q.pop();
		inQ[0] = 1;
		dist[0] = 0;
		Q.push(0);
		while(!Q.empty()){
			int cur = Q.front();
			Q.pop();
			inQ[cur] = 0;
			for(auto i:edg[cur]){
				if(!able[cur][i]) continue;
				if(dist[i] == -1 || dist[i] > dist[cur] + gr[cur][i]){
					pr[i] = cur;
					dist[i] = dist[cur] + gr[cur][i];
					if(!inQ[i]){
						inQ[i] = 1;
						Q.push({i});
					}
				}
 			}
		}
		if(dist[n+m+1] == -1) break;
		cnt++;
		res += dist[n+m+1];
		for(int i = n+m+1;i!=0;i = pr[i]){
			able[i][pr[i]] = 1;
			able[pr[i]][i] = 0;	
		}
	}
	printf("%d\n%d",cnt,res);
}