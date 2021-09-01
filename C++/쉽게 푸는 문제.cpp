#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int cnt = 1,a[1005];
	for(int i = 1;;i++){
		for(int j=0;j<i;j++){
			if(cnt > 1000) break;
			a[cnt++] = i; 
		}
		if(cnt > 1000) break;
	}
	int x,y,sum = 0;
	cin >> x >> y;
	for(int i=x;i<=y;i++) sum += a[i];
	cout << sum;
}