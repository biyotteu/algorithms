//백준 15673


#include <bits/stdc++.h>

using namespace std;

int n,sum[100005],bsum[100005],cook[100005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> cook[i];
	for(int i=1;i<=n;i++) sum[i] = sum[i-1] + cook[i];
	for(int i=n;i>0;i--) sum[i] = sum[i+1] + cook[i];
	int a = 0,k;
	for(int i=1;i<=n;i++){
		a = min(a,sum[i]);

	}
}