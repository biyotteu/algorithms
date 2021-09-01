#include <bits/stdc++.h>

using namespace std;

int n,m,res,dp[5005][5005];
vector<int> A,B;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		A.push_back(x);
	}
	for(int i=0;i<m;i++){
		int x;
		cin >> x;
		B.push_back(x);
	}
	memset(dp,-1,sizeof(dp));
	for(int k=0;k<m;k++){
		for(int i=0;i<m-k;i++){
			if(k == 0){
			 	for(int j=0;j<n;j++) 
			 		if(A[j] == B[i]){
			 			dp[i][k] = j;
			 			res = max(res,k+1);
			 			break;
			 		}
			}
			else{
				if(dp[i][k-1] == -1) continue;
				for(int j=dp[i][k-1]+1;j<n;j++){
					if(A[j] == B[i+k]){
						dp[i][k] = j;
						res = max(res,k+1);
						break;
					}
				}
			}
		}
	}
	cout << res;
}