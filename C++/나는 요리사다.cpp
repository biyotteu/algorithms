#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int sum=0,idx;
	for(int i=1;i<=5;i++){
		int cur = 0;
		for(int j=0;j<4;j++){
			int x;
			cin >> x;
			cur += x;
		}
		if(cur > sum){
			sum = cur;
			idx = i;
		}
	}	
	cout << idx << ' ' << sum;
}