#include <bits/stdc++.h>

using namespace std;

vector<int> coin;
int DP[10005];
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		coin.push_back(x);
	}
	fill(DP,DP+k+1,1E9);
	DP[0]=0;
    for(auto j:coin){
        for(int i=1;i<=k;i++){
			if(i<j) continue;
			DP[i] = min(DP[i],DP[i-j]+1);
		}
	}
	if(DP[k]==1E9){
		printf("-1");
		return 0;
	}
	printf("%d",DP[k]);
}
