#include <bits/stdc++.h>

using namespace std;

struct info
{
	int x, y, z;
	info() {}
	info(int a, int b, int c) { 
		x = a, y = b, z = c;
	}
    bool operator<(info t) const{
		return abs(y - z) > abs(t.y - t.z);
	}
};
int n, A, B, res;
vector<info> num;
int main()
{
	while (1) {
		scanf("%d %d %d", &n, &A, &B);
		if (n + A + B == 0) return 0;
		num.clear();
		res = 0;
		for (int i = 0; i < n; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			num.push_back(info(x,y,z));
		}
		sort(num.begin(), num.end());
		for (int i = 0; i < n; i++) {
			if (num[i].y > num[i].z) {
				if (A >= num[i].x) {
					res += num[i].y * num[i].x;
					A -= num[i].x;
				}
				else {
					res += A * num[i].y;
					res += (num[i].x - A) * num[i].z;
					B -= (num[i].x - A);
					A = 0;
				}
			}
			else if (num[i].y == num[i].z) {
				if (A > B) {
					if (A >= num[i].x) {
						res += num[i].y * num[i].x;
						A -= num[i].x;
					}
					else {
						res += A * num[i].y;
						res += (num[i].x - A) * num[i].z;
						B -= (num[i].x - A);
						A = 0;
					}
				}
				else {
					if (B >= num[i].x) {
						res += num[i].z * num[i].x;
						B -= num[i].x;
					}
					else {
						res += B * num[i].z;
						res += (num[i].x - B) * num[i].y;
						A -= (num[i].x - B);
						B = 0;
					}
				}
			}
			else {
				if (B >= num[i].x) {
					res += num[i].z * num[i].x;
					B -= num[i].x;
				}
				else {
					res += B * num[i].z;
					res += (num[i].x - B) * num[i].y;
					A -= (num[i].x - B);
					B = 0;
				}
			}
		}
		printf("%d",res);
	}
}
