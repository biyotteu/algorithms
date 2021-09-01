#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<int> Q;
	long long n;
	cin >> n;
	for(int i=0;i<n;i++){
		long long x;
		cin >> x;
		Q.push(-x);
	}
	int res = 0;
	while(Q.size() > 1){
		int a = Q.top();
		Q.pop();
		int b = Q.top();
		Q.pop();
		Q.push(a+b);
		res -= (a+b);
	}
	cout << res;
}