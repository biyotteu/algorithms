#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> num;
long long int res, seg[(1<<18)];
int k;
void update(int v,int i){
	int idx = i+k;
	seg[idx] = v;
	while(idx>>=1) seg[idx] = seg[(idx<<1)] + seg[(idx<<1)+1];
}
long long int sum(int a,int b){
	long long int ret = 0;
	a += k, b += k;
	while(a<=b){
		if(a%2) ret += seg[a++];
		if(b%2 == 0) ret += seg[b--];
		a >>= 1, b >>= 1;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(k=1;k<n;k<<=1);
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		num.push_back({x,i});
	}
	sort(num.begin(),num.end());
	for(auto i:num){
		res += (i.second - 1 - sum(1,i.second))*sum(i.second,n);
		update(1,i.second);
	}
	cout << res;
}