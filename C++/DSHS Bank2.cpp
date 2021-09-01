#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<long long,long long>> bank;
vector<long long> X,Y;
vector<long long int> XS,YS;
long long int f(int v){
	int xi = upper_bound(X.begin(),X.end(),bank[v].first) - X.begin();
	int yi = upper_bound(Y.begin(),Y.end(),bank[v].second) - Y.begin();
	long long int xx,yy;
	xx = (xi)*bank[v].first - 2*XS[xi-1] + XS[n-1] - (n-xi)*bank[v].first;
	yy = (yi)*bank[v].second - 2*YS[yi-1] + YS[n-1] - (n-yi)*bank[v].second;
	return xx+yy;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		bank.push_back({x,y});
		X.push_back(x);
		Y.push_back(y);
	}
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	long long int ssx,ssy;
	ssx = ssy = 0;
	for(int i=0;i<n;i++){
		ssx += X[i];
		ssy += Y[i];
		XS.push_back(ssx);
		YS.push_back(ssy);
	}
	long long int res = 123456789123456789LL;
	int idx = -1;
	for(int i=0;i<n;i++){
		long long int k = f(i);
		if(res > k){
			res = k;
			idx = i+1;
		}
	}
	cout << idx;
}