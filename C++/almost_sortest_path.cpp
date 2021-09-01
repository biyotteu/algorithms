#include <bits/stdc++.h>
#define INF (1<<30)
using namespace std;

struct info {
	int x, y;
	info() {}
	info(int a, int b) {x = a, y = b;}
};
int n, m;
int _start_, _end;
vector<info> road[1005];
int spfa() {
	int inQ[1005], dist[1005];
	info parent[1005];
	queue<int> Q;
	for (int i = 0; i < n; i++) {
		inQ[i] = 0;
		dist[i] = INF;
	}
	Q.push(_start_);
	inQ[_start_] = 1;
	dist[_start_] = 0;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		inQ[cur] = 0;
		int idx = 0;
		for (auto i : road[cur]) {
			if (dist[i.x] > dist[cur] + i.y) {
				dist[i.x] = dist[cur] + i.y;
				parent[i.x] = info(cur,idx);
				if (!inQ[i.x]) {
					Q.push(i.x);
					inQ[i.x] = 1;
				}
			}
			idx++;
		}
	}

	if(dist[_end] == INF) return INF;
	int v = _end;
	while(v!=_start_){
		road[parent[v].x].erase(road[parent[v].x].begin()+parent[v].y);
		v = parent[v].x;
	}
	return dist[_end];
}
int main()
{
	while (1) {
		scanf("%d %d", &n, &m);
		if(n == m && n == 0) return 0;
		scanf("%d %d", &_start_, &_end);
		for(int i=0;i<n;i++) road[i].clear();
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			road[a].push_back(info(b, c));
		}
		int k = spfa();
		if(k == INF){
			printf("-1\n");
			continue;
		}
		int res;
		while(k == (res = spfa()));
		if(res == INF){
			printf("-1\n");
			continue;
		}
		printf("%d\n", res);
	}
}
