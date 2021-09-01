#include <bits/stdc++.h>

using namespace std;

vector<int> level;
int main()
{
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		if(i==0 || level.back() < x){ 
			level.push_back(x);
			cnt++;
		}
		else level[lower_bound(level.begin(),level.end(),x) - level.begin()] = x;
	}
	printf("%d",cnt);
}