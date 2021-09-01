#include <bits/stdc++.h>

using namespace std;

int n,s,a[25],cnt;
void f(int v,int sum){
	if(n == v){
		if(sum == s)
		 cnt++;
		return;
	}
	f(v+1,sum+a[v+1]);
	f(v+1,sum);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> s;
	for(int i=1;i<=n;i++) cin >> a[i];
	f(0,0);
	if(s == 0) cnt-=1;
	cout << cnt;
}