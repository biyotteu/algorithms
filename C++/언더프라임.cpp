#include <bits/stdc++.h>
#define lim 100005

using namespace std;

int dp[lim],res;
vector<int> pri;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=2;i<=m;i++){
		if(dp[i]) continue;
		pri.push_back(i);
		for(int j=(i<<1);j<=m;j+=i) dp[j] = 1;
	}
	dp[0] = dp[1] = 1;
	for(int i=n;i<=m;i++){
		int cnt = 0;
		int tmp = i;
		for(auto j:pri){
			while(1){
				if(tmp%j == 0){
					tmp/=j;
					cnt++;
				}
				else break;
			}
			if(tmp == 1) break;
		}
		if(!dp[cnt]) res++;	
	}
	printf("%d",res);
}