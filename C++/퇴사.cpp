#include <bits/stdc++.h>

using namespace std;

int n,res;
vector<pair<int,int>> s;
void f(int day, int sum){
    if (day == n + 1){
        res = max(res, sum);
        return;
    }
    if(day + s[day].first <= n + 1) f(day + s[day].first, sum + s[day].second);
    if(day + 1 <= n + 1) f(day + 1, sum);
}
int main()
{
	scanf("%d",&n);
	s.push_back({0,0});
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		s.push_back({x,y});
	}
	f(1,0);
	printf("%d",res);
}

