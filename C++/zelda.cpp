#include <bits/stdc++.h>

using namespace std;

struct info {
	int x, y, cnt;
	info() {}
	info(int a, int b, int c) {
		x = a, y = b, cnt = c;
	}
	bool operator <(info A)const { return cnt > A.cnt; }
};
int n, miro[130][130], visit[130][130], res = (1 << 30), X[4] = {1, 0, -1, 0}, Y[4] = {0, 1, 0, -1};
priority_queue<info> Q;
int main()
{
	for(int t=1; ;t++) {
		scanf("%d",&n);
		if(!n) return 0;
		res = (1 << 30);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) visit[i][j] = 0;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &miro[i][j]);
		Q.push(info(1, 1, miro[1][1]));
		while (!Q.empty()) {
			info cur = Q.top();
			Q.pop();
			if (visit[cur.x][cur.y] || cur.x > n || cur.x < 1 || cur.y > n || cur.y < 1) continue;
			visit[cur.x][cur.y] = 1;
			if (cur.x == n && cur.y == n) {
				res = min(res, cur.cnt);
				continue;
			}
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + X[i];
				int ny = cur.y + Y[i];
				Q.push(info(nx, ny, cur.cnt + miro[nx][ny]));
			}
		}
		printf("Problem %d: %d\n",t, res);
	}
}
