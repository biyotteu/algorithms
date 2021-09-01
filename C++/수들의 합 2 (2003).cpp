#include <bits/stdc++.h>

using namespace std;

int a[10005],n,m,cnt;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	int l=1,r=1,v=0;
	while(1){
		if(l>n) break;
		if(v == m) cnt++;
		if(v >= m) v-=a[l++];
		else v+=a[r++];
	}
	cout << cnt;
}