#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,sum = 0;
	cin >> n;
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		if(i == 1){
			cout << x << ' ';
			sum = x*i;
			continue;
		}
		cout << x*i - sum << ' ';
		sum = x*i;
	}
}