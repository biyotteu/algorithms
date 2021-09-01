//백준 6118번
//최단거리 문제
//정말 단순한 최단거리 문제다
//구한 최단거리중의 최대 거리를 가진 노드를 구해주면 된다.
//다익스트라와 spfa와 같은 알고리즘을 이용해 풀 수 있다.

#include <bits/stdc++.h>

using namespace std; 

int n,m;
vector<int> graph[20005];
void spfa(){
	int dist[20005],inQ[20005];
	queue<int> Q;
	for(int i=1;i<=n;i++){
		inQ[i] = 0, dist[i] = (1<<29);
	}
	Q.push(1);
	inQ[1] = 1;
	dist[1] = 0;
	while(!Q.empty()){
		int  cur = Q.front();
		Q.pop();
		inQ[cur] = 0;
		for(auto i:graph[cur]){
			if(dist[i] > dist[cur] + 1){
				dist[i] = dist[cur] + 1;
				if(!inQ[i]){
					inQ[i] = 1;
					Q.push(i);
				}
			}
		}
	}
	vector<int> res;
	int ma = 0;
	for(int i=1;i<=n;i++){
		if(dist[i] != (1<<29)){
			if(dist[i] > ma){
				res.clear();
				res.push_back(i);
				ma = dist[i];
			}else if(dist[i] == ma){
				res.push_back(i);
			}
		}
	}
	sort(res.begin(),res.end());
	printf("%d %d %d",res[0],ma,res.size());
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		graph[x].push_back(y);	
		graph[y].push_back(x);	
	}
	spfa();
}