#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y;
	bool operator<(info A)const{
		return y > A.y;
	}
};
int ret,cnt,n,m,h,idx[1005][1005],res[1000005];
priority_queue<info> Q;
vector<info> graph[1000005];
int main(){
	scanf("%d %d %d",&n,&m,&h);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) idx[i][j] = ++cnt;
	for(int i=1;i<=cnt;i++) res[i] = -1; 
	for(int i=0;i<=n;i++){
		for(int j=0;j<m;j++){
			int x;
			scanf("%d",&x);
			if(x == -1) continue;
			if(i == 0){
				graph[0].push_back({idx[i][j],x});
				graph[idx[i][j]].push_back({0,x});
			}else if(i == n){
				graph[0].push_back({idx[i-1][j],x});
				graph[idx[i-1][j]].push_back({0,x});
			}else{
				graph[idx[i][j]].push_back({idx[i-1][j],x});
				graph[idx[i-1][j]].push_back({idx[i][j],x});
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<=m;j++){
			int x;
			scanf("%d",&x);
			if(x == -1) continue;
			if(j==0){
				graph[0].push_back({idx[i][j],x});
				graph[idx[i][j]].push_back({0,x});
			}else if(j==m){
				graph[0].push_back({idx[i][j-1],x});
				graph[idx[i][j-1]].push_back({0,x});
			}else{
				graph[idx[i][j]].push_back({idx[i][j-1],x});
				graph[idx[i][j-1]].push_back({idx[i][j],x});
			}
		}
	}
	for(auto i:graph[0])
		Q.push({i.x,i.y});
	while(!Q.empty()){
		info cur = Q.top();
		Q.pop();
		if(res[cur.x]!=-1) continue;
		res[cur.x] = cur.y;
		for(auto i:graph[cur.x]){
			Q.push({i.x,max(cur.y,i.y)});
		}
	}
	for(int i=1;i<=cnt;i++){
		if(res[i]==-1) ret+=h;
		else ret+=res[i];
	}
	printf("%d",ret);
}