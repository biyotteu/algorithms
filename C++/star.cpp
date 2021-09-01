#include <bits/stdc++.h>

using namespace std;

int n;
int DP[100005],last = 123,cnt = 1;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(last == x) cnt++;
		DP[cnt]++;
		last = x;
	}
	int res = 0;
	for(int i=0;i<cnt;i++)	res = max(res,DP[i]+DP[i+1]+DP[i+2]);
	printf("%d",res);
}
