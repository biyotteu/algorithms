#include <bits/stdc++.h>

using namespace std;

struct info {
	int x, y;
	info() {x = 0, y = 0;}
	info(int a, int b) {
		x = a, y = b;
	}
	bool operator<(const info v)const {
		return x > v.x;
	}
};
int n, m, s, e, t, fb[3005], sum[3005][3005], DP[3005][3005];
info mini[3005][3];
deque<info> dq[3005];
int get(int i, int j) {
	for (int k = 0; k < 3; k++) {
		if (mini[i][k].y == j || mini[i][k].y == fb[j]) continue;
		return mini[i][k].x;
	}
}
int main()
{
	scanf("%d %d %d %d %d", &n, &m, &s, &e, &t);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &sum[i][j]);
			sum[i][j] += sum[i][j - 1];
		}
	}
	for (int i = 1; i <= n; i++) scanf("%d", &fb[i]);
	int res = 1E9;
	for (int i = 1; i <= m; i++) {
		priority_queue<info> Q;
		for (int j = 1; j <= n; j++) {
			if (i >= s) {
				int v = get(i-s, j) - sum[j][i - s];
				while (!dq[j].empty() && dq[j].back().x >= v) dq[j].pop_back();
				dq[j].push_back(info(v, i - s));
			}
			while (!dq[j].empty() && dq[j].front().y < i - e) dq[j].pop_front();
			if (dq[j].empty() || dq[j].front().x == 1E9) DP[i][j] = 1E9;
			else DP[i][j] = dq[j].front().x + t + sum[j][i];
			Q.push(info(DP[i][j], j));
		}
		for (int j = 0; j < 3; j++) mini[i][j] = info(1E9, 0);
		for (int j = 0; j < 3; j++) {
			mini[i][j] = Q.top();
			Q.pop();
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m - e; j < m; j++) {
			int v = get(j, i);
			if (v == 1E9) continue;
			res = min(res, v + sum[i][m] - sum[i][j]);
		}
	}
	printf("%d",res);
}