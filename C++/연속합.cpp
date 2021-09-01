#include <bits/stdc++.h>

using namespace std;

int n,k,sum[5001],res;
int main(){
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		sum[i] = sum[i-1] + x;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			if((sum[i] - sum[j]) == k)res++;
		}
	}
	cout << res;
}