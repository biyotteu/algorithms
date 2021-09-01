#include <bits/stdc++.h>

using namespace std;

int n,a[4005],b[4005],c[4005],d[4005];
long long int res;
vector<int> num1,num2;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			num1.push_back(a[i]+b[j]);
			num2.push_back(c[i]+d[j]);
		}
	sort(num2.begin(),num2.end());
	for(int i=0;i<num1.size();i++){
		res += upper_bound(num2.begin(),num2.end(),-num1[i])-lower_bound(num2.begin(),num2.end(),-num1[i]);
	}
	cout << res;
x}