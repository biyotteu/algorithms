#include <bits/stdc++.h>

using namespace std;

struct pos{
	int x,y;
};
int n,m,inQ[2005];
long long dist[2005],res;
vector<pos> pr;
vector<vector<pos>> edg;
queue<int> Q;
int main(){
	while(scanf("%d %d",&n,&m) != EOF){
		pr.clear();
		pr.resize(n*2+5);
		edg.clear();
		edg.resize(n*2+5);
		for(int i=2;i<n;i++) edg[i].push_back({i+n,0});
		for(int i=0;i<m;i++){
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			if(x == 1) edg[x].push_back({y,z});
			else edg[x+n].push_back({y,z});
		}
		res = 0;
		for(int p=0;p<2;p++){
			memset(inQ,0,sizeof(inQ));
			memset(dist,-1,sizeof(dist));
			while(!Q.empty())Q.pop();
			dist[1] = 0;
			inQ[1] = 1;
			pr[1] = {1,0};
			Q.push(1);
			while(!Q.empty()){
				int cur = Q.front();
				Q.pop();
				inQ[cur] = 0;
				for(int k=0;k<edg[cur].size();k++){
					pos i = edg[cur][k];
					if(dist[i.x] == -1 || dist[i.x] > dist[cur] + i.y){
						dist[i.x] = dist[cur] + i.y;
						pr[i.x] = {cur,k};
						if(!inQ[i.x]){
							inQ[i.x] = 1;
							Q.push(i.x);
						}
					}
				}
			}
			res += dist[n];
			for(int i=n;i!=1;i=pr[i].x){
				edg[i].push_back({pr[i].x,-edg[pr[i].x][pr[i].y].y});
				edg[pr[i].x].erase(edg[pr[i].x].begin()+pr[i].y);
			}
		}
		printf("%lld\n",res);
	}
}