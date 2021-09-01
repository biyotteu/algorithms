#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> num;
long long int f(int v){
	long long int ret = 0;
	for(int i=0;i<n;i++) ret += abs(i*v - num[i]);
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		num.push_back(x);
	}
	int l = 1,r = 1000000000/n+1;
	long long int ret;
	ret = min(f(l),f(r));
	while(l+2<r){
		int mid1 = (l*2+r)/3, mid2 = (l+r*2)/3;
		long long int a = f(mid1) , b = f(mid2);
		if(a > b) l = mid1;
		else r = mid2;
		ret = min(ret,min(a,b));
	}
	cout << ret;
}