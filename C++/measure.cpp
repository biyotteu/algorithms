#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	vector<int> num;
	scanf("%d",&n);
	num.resize(n);
	for(int i=0;i<n;i++) scanf("%d",&num[i]);
	sort(num.begin(),num.end());
	printf("%d",num[0]*num[n-1]);
}