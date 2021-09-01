#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	vector<int> A,B;
	cin >> n;
	A.resize(n);
	B.resize(n);
	for(int i=0;i<n;i++) cin >> A[i];
	for(int i=0;i<n;i++) cin >> B[i];
	sort(A.begin(),A.end());
	sort(B.rbegin(),B.rend());
	int res = 0;
	for(int i=0;i<n;i++) res += A[i]*B[i];
	cout << res;
}