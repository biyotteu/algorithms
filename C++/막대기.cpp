#include <bits/stdc++.h>

using namespace std;

int n,k,res;
vector<pair<int,int>> stick;
vector<int> X,Y;
vector<int> XX,YY;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		stick.push_back({x,y});
		X.push_back(x);
		Y.push_back(y);
	}
	sort(stick.begin(),stick.end());
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	XX.resize(n+1);
	YY.resize(n+1);
	X.erase(unique(X.begin(),X.end()),X.end());
	Y.erase(unique(Y.begin(),Y.end()),Y.end());
	for(int i=0;i<n;i++){
		int xidx = lower_bound(X.begin(),X.end(),stick[i].first) - X.begin();
		int yidx = lower_bound(Y.begin(),Y.end(),stick[i].second) - Y.begin();
		int ret = k + abs(stick[i].first - stick[i].second); 
		int a = XX[xidx], b = YY[yidx];
		XX[xidx] = max(a,b+ret);
		YY[yidx] = max(b,a+ret);
		res = max(XX[xidx],res);
		res = max(YY[yidx],res);
	}
	cout << res;
}