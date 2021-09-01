#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> X;
int main(){
	cin >> n;
	X.push_back(0);
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		X.push_back(x);
	}
	int m;
	cin >> m;
	for(int i=0;i<m;i++){
		int x;
		cin >> x;
		if(x < n && X[x]+1 < X[x+1]) X[x]++;
		else if(x == n && X[x]+1 <= 2019) X[x]++;
	}
	for(int i=1;i<=n;i++) cout << X[i] << "\n";
}