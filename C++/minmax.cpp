#include <bits/stdc++.h>

using namespace std;

int n, m, idx;
long long int seg[500000], tree[500000];
void find(int l, int r)
{
	long long int maxi = 0, mini = (1<<30);
	while (l <= r)
	{
		if (l % 2 == 1) {
			maxi = max(seg[l], maxi);
			mini = min(tree[l], mini);
			l++;
		}
		if (r % 2 == 0) {
			maxi = max(seg[r], maxi);
			mini = min(tree[r], mini);
			r--;
		}
		l >>= 1;
		r >>= 1;
	}
	printf("%lld %lld\n", mini,maxi);
	return;
}
int main()
{
	scanf("%d %d", &n, &m);
	fill(tree,tree+500000,(1<<30));
	for (idx = 1; idx < n; idx <<= 1);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &seg[idx + i]);
		tree[idx + i] = seg[idx + i];
	}
	for (int i = idx - 1; i >= 1; i--) {
		seg[i] = max(seg[i << 1], seg[(i << 1) | 1]);
		tree[i] = min(tree[i << 1], tree[(i << 1) | 1]);
	}
	while (m--) {
		int u, v;
		scanf("%d %d", &u, &v);
		find((u - 1) | idx, (v - 1) | idx);
	}
	return 0;
}