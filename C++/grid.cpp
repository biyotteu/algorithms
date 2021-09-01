#include <bits/stdc++.h>

using namespace std;

int n, m, X[4] = {1, 0, -1, 0}, Y[4] = {0, 1, 0, -1}, cnt = 1, res = 1E9;
int game[105][105], visit[105][105];
vector<int> graph[10005];
void dfs(int x, int y, int turn) {
	if (x < 1 || y < 1 || x > n || y > m) return;
	if (visit[x][y] || turn != game[x][y]) return;
	visit[x][y] = cnt;
	for (int i = 0; i < 4; i++) dfs(x + X[i], y + Y[i], turn);
	return;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &game[i][j]);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (visit[i][j]) continue;
			dfs(i, j, game[i][j]);
			cnt++;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 0; k < 4; k++) {
				int x = i + X[k];
				int y = j + Y[k];
				if (x < 1 || y < 1 || x > n || y > m) continue;
				if (visit[x][y] != visit[i][j]) {
					graph[visit[i][j]].push_back(visit[x][y]);
				}
			}
	for (int i = 1; i < cnt; i++) {
		sort(graph[i].begin(), graph[i].end());
		unique(graph[i].begin(), graph[i].end());
	}

	for (int i = 1; i < cnt; i++) {
		int Q[10000], ch[10001] = { 0, }, rear = 0, fron = 1;
		ch[i] = 1; Q[0] = i; 
		while (rear < fron && ch[Q[rear]] < res) {
			for (auto k : graph[Q[rear]])
				if (!ch[K]) {
					ch[k] = ch[Q[rear]] + 1;
					Q[fron++] = k;
				}
			rear++;
		}
		res = ch[Q[fron - 1]];
	}
	printf("%d", res - 1);
}