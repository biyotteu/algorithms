#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> Q;
vector<int> X,Y;
vector<pair<int,int>> num;
int n;
long long int xsum[500005],ysum[500005];
long long int diff(int v){
	int xk = lower_bound(X.begin(),X.end(),num[v].first) - X.begin();
	int yk = lower_bound(Y.begin(),Y.end(),num[v].second) - Y.begin();
	long long int ret = 0;
	ret += (num[v].first*n - xsum[n]) + 2*((xsum[n]-xsum[xk]) - (n-xk)*num[v].first);
	ret += (num[v].second*n - ysum[n]) + 2*((ysum[n]-ysum[yk]) - (n-yk)*num[v].second);
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	X.push_back(-(1<<30));
	Y.push_back(-(1<<30));
	num.push_back({-1,-1});
	for(int i=1;i<=n;i++){
		double x,y;
		cin >> x >> y;
		X.push_back(x);
		Y.push_back(y);
		num.push_back({x,y});
	}
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	for(int i=1;i<=n;i++){
		xsum[i] = xsum[i-1] + X[i];
		ysum[i] = ysum[i-1] + Y[i];
	}
	long long int res = diff(1);
	int idx = 1;
	for(int i=2;i<=n;i++){
		if(res > diff(i)){
			res = diff(i);
			idx = i;
		}
	}
	cout << idx;
}