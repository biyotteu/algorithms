#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int cnt = 0, sum = 0;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		if(x) cnt++;
		else cnt = 0;
		sum += cnt;
	}	
	cout << sum;
}