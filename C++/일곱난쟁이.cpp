#include <bits/stdc++.h>

using namespace std;

int na[9],visit[9];
void f(int v,int sum,int cnt){
	if(v == 9){
		if(sum == 100 && cnt == 7){
			vector<int> res;
			for(int i=0;i<9;i++)
				if(visit[i] == 1) res.push_back(na[i]);
			sort(res.begin(),res.end());
			for(auto i:res) printf("%d\n",i);
			exit(0);
		}
		return;
	}
	visit[v] = 1;
	f(v+1,sum+na[v],cnt+1);
	visit[v] = 0;
	f(v+1,sum,cnt);
	return;
}
int main(){
	for(int i=0;i<9;i++) scanf("%d",&na[i]);
	f(0,0,0);
}