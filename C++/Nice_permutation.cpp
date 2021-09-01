#include <bits/stdc++.h>

using namespace std;

int n;
long long int sum[100005], s;
int parametric(int left, int right, int idx) {
	int res = 0, flag = 0;
	int mid = (left + right) / 2;
	long long int ret1, ret2;
	while (left <= right) {
		mid = (left + right) / 2;
		ret1 = sum[idx + mid - 1] - sum[idx - 1];
		ret2 = sum[idx + mid * 2 - 1] - sum[idx + mid - 1];
		if (ret1 + ret2 <= s + s) {
			if (ret1 <= s && ret2 <= s) {
				res = mid;
				left = mid + 1;
			}
			else{
				flag = 1;
				break;
			}
		}
		else right = mid - 1;
	}
	if (flag)
	{
		for (int j = right; j >= res; j--)
		{
			ret1 = sum[idx + j - 1] - sum[idx - 1];
			ret2 = sum[idx + j * 2 - 1] - sum[idx + j - 1];
			if (ret1 <= s && ret2 <= s) return j;
		}
	}
	else return res;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("#%d ", t);
		scanf("%d %lld", &n, &s);
		for (int i = 1; i <= n; i++) {
			long long int x;
			scanf("%lld", &x);
			sum[i] = sum[i - 1] + x;
		}
		for (int i = 1; i < n; i++) {
			printf("%d ", parametric(0, (n - i + 1) / 2, i) * 2);
		}
		printf("0\n");
	}
}
