#include <bits/stdc++.h>

using namespace std;

int n,res = (1<<30);
vector<int> num,ch[5005];

void f(int idx,int cnt){
	if(idx == n){
		res = min(res,cnt);
		return;
	}
	for(int i=1;i<=cnt;i++){
		if(ch[i].size()==1 || ch[i][ch[i].size()-1] - ch[i][ch[i].size()-2] == num[idx] - ch[i][ch[i].size()-1])
		{
			ch[i].push_back(num[idx]);
			f(idx+1,cnt);
			ch[i].pop_back();
		}
	}
	ch[cnt+1].push_back(num[idx]);
	f(idx+1,cnt+1);
	ch[cnt+1].pop_back();
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		num.clear();
		res = (1<<30);
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			num.push_back(x);
		}
		ch[1].push_back(num[0]);
		f(1,1);
		ch[1].pop_back();
		printf("#%d %d\n",t,res);
	}
}