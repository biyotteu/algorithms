#include <bits/stdc++.h>

using namespace std;

long long int t,n,m,a[1005],b[1005],res;
vector<long long int> A,B;
int main(){
	ios::sync_with_stdio(false);
	cin >> t >> n;
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		a[i] = a[i-1] + x;
	}
	cin >> m;
	for(int i=1;i<=m;i++){
		int x;
		cin >> x;
		b[i] = b[i-1] + x;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j+i<=n;j++)
			A.push_back(a[j+i] - a[j]);
	for(int i=1;i<=m;i++)
		for(int j=0;j+i<=m;j++)
			B.push_back(b[j+i] - b[j]);
	sort(B.begin(),B.end());
	for(int i=0;i<A.size();i++)
		res += upper_bound(B.begin(),B.end(),t-A[i])-lower_bound(B.begin(),B.end(),t-A[i]);
	cout << res;
}