#include <bits/stdc++.h>

using namespace std;

int f(int v){
	if(!v) return 1;
	int cnt = 0;
	while(v){
		if(v%10 == 0) cnt++;
		v/=10;
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int a,b,res = 0;
		cin >> a >> b;
		for(int i=a;i<=b;i++) res += f(i);
		cout << res << '\n'; 
	}
}