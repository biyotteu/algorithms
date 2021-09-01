#include <bits/stdc++.h>

using namespace std;

int n, idx[300005], parent[300005], cnt;
int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("#%d ", t);
		cnt = 0;
		scanf("%d", &n);
		scanf("%d", &idx[0]);
		for (int i = 1; i <= n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			idx[i] = x;
			parent[i] = y;
			x = i;
			while (x) {
				if (idx[parent[x]] < idx[x]) {
					idx[parent[x]] = idx[x];
					x = parent[x];
					cnt++;
				}
				else break;
			}
		}
		printf("%d", cnt);
	}
}