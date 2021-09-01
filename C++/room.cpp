#include <bits/stdc++.h>

using namespace std;

int stud[7][2], sum;
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		stud[y][x]++;
	}
	int a = stud[1][0] + stud[1][1] + stud[2][0] + stud[2][1];
	sum += a / k;
	if (a % k != 0) sum++;
	for (int i = 3; i <= 6; i += 2)
		for (int j = 0; j <= 1; j++) {
			a = stud[i][j] + stud[i + 1][j];
			sum += a / k;
			if (a % k != 0) sum++;
		}
	printf("%d", sum);
}