#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long sum = 0,half = 0;
	cin >> n;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		sum += x;
		half += x/2;
	}
	if(sum%3 == 0 && sum/3 <= half) cout << "YES";
	else cout << "NO";
}