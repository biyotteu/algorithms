#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,cnt=0;
	cin >> n;
	for(int i=1;i<=500;i++){
		for(int j=i+1;j<=500;j++){
			if(j*j-i*i == n) cnt++;
		}
	}
	cout << cnt;
}