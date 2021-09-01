#include <bits/stdc++.h>

using namespace std;

int DP[1005];
int main(){
	int n,MAX=0;
	vector<int> num;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		num.push_back(x);
		for(int j=0;j<i;j++) if(num[i] < num[j]) DP[i] = max(DP[i],DP[j]+1);
		MAX = max(MAX,DP[i]);
	}
	printf("%d", MAX+1);
}
