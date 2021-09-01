#include <bits/stdc++.h>
#define INF -(1<<29)

using namespace std;

long long int n,m,a,b,MM;
long long int res;
vector<long long int> X,Y,XV,YV;
int main()
{	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++){
		long long int x,y;
		cin >> x >> y;
		X.push_back(x);
		XV.push_back(y);
	}
	cin >> m;
	YV.resize(m+1);
	for(int i=0;i<m;i++){
		long long int x,y;
		cin >> x >> y;
		Y.push_back(x);
		YV[i+1] = YV[i]+y;
	}
	cin >> a >> b;
	for(int i=0;i<n;i++){
		long long int s,e;
		s = lower_bound(Y.begin(),Y.end(),X[i]+a) - Y.begin();
		e = lower_bound(Y.begin(),Y.end(),X[i]+b+1) - Y.begin();
		res += (YV[e] - YV[s]) * XV[i];
	}
	cout << res;
}