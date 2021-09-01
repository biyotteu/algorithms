#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<int> Q1,Q2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		if(i%2 == 0) Q1.push(x);
		else Q2.push(-x);
		if(Q1.size() && Q2.size()){
			int a = Q1.top();
			int b = -Q2.top();
			if(a > b){
				Q1.pop();
				Q2.pop();
				Q1.push(b);
				Q2.push(-a);
			}
		}
		cout << Q1.top() << "\n";
	}
}