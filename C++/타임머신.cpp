#include <bits/stdc++.h>
#define INF 1000000000L
using namespace std;

int n,m;
vector<pair<int,int>> gr[505];
int bal(){
	vector<long long> dist(n+1,INF);
	int  cmp = 0;
	dist[1] = 0;
	for(int q=0;q<n;q++){
		for(int i=1;i<=n;i++){
			for(auto j:gr[i]){
				if(dist[i] != INF && dist[j.first] > dist[i] + j.second){
					dist[j.first] = dist[i] + j.second;
					if(q == n-1) cmp = 1;
				}
			}
		}	
	}
	if(cmp) puts("-1");
	else for(int i=2;i<=n;i++)	printf("%lld\n",dist[i] == INF ? -1 : dist[i]);
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		gr[x].push_back({y,z});
	}
	bal();
}