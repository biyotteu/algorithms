#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	vector<int> num;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		num.push_back(x);
	}
	sort(num.begin(), num.end());
	for (int i : num)
		printf("%d ", i);
}
