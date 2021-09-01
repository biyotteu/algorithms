#include <bits/stdc++.h>
#define	INF (1<<29)
using namespace std;

struct info
{
	int x,y;
	info(int a,int b){
		x = a, y = b;
	}
	info(){ x = 0, y = 0;}
};
int n,s,e;
vector<info> graph[100005];
int spfa(){
	vector<int> dist,inQ;
	vector<info> next;
	queue<int> Q;
	dist.resize(n+1,INF);
	inQ.resize(n+1);
	next.resize(n+1);
	inQ[s] = 1;
	Q.push(s);
	dist[s] = 0;
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		inQ[cur] = 0;
		for(auto i:graph[cur]){
			if(dist[cur] + i.y < dist[i.x]){
				dist[i.x] = dist[cur] + i.y;
				next[i.x] = info(cur,i.y); 
				if(!inQ[i.x]){
					inQ[i.x] = 1;
					Q.push(i.x);
				}
			}
		}
	}
	int mm = 0;
	s = e;
	while(next[s].x){
		mm = max(mm,next[s].y);
		s = next[s].x;
	}
	return dist[e] - mm;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s >> e;
	for(int i=0;i<n-1;i++){
		int x,y,z;
		cin >> x >> y >> z;
		graph[x].push_back(info(y,z));
		graph[y].push_back(info(x,z));
	}
	cout << spfa();
}