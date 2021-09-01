#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pp = pair<ll,ll>;
int ccw(pp x, pp y, pp z){
	ll tmp = x.first*y.second + y.first*z.second + z.first*x.second;
	tmp = tmp - (x.second*y.first + y.second*z.first + z.second*x.first); 
	if(tmp > 0) return 1;
	else if(tmp < 0) return -1;
	else return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	pp v[4];
	for(int i=0;i<4;i++) cin >> v[i].first >> v[i].second;
	int ab = ccw(v[0],v[1],v[2]) * ccw(v[0],v[1],v[3]);
	int cd = ccw(v[2],v[3],v[0]) * ccw(v[2],v[3],v[1]);
	double g1 = (double)(v[0].second - v[1].second) / (double)(v[0].first - v[1].first);
	double g2 = (double)(v[2].second - v[3].second) / (double)(v[2].first - v[3].first);
	double y = g1*(v[2].second - g2*v[2].first) - g2*(v[0].second - g1*v[0].first);
	double x = v[2].second - g2*v[2].first - v[0].second + g1*v[0].first;
			
	if(ab == 0 && cd == 0){
		if(v[0] > v[1]) swap(v[0],v[1]);
		if(v[2] > v[3]) swap(v[2],v[3]);
		if((v[2] <= v[1] && v[0] <= v[3])){
			cout << 1 << "\n";
			if(g1 == g2){
				if(v[1] == v[2] && v[0] <= v[2]) cout << v[1].first << ' ' << v[1].second;
				else if(v[0] == v[3] && v[0] >= v[2]) cout << v[0].first << ' ' << v[0].second;
			}else{
				cout << fixed;
				cout.precision(9);
				cout << x/(g1 -g2) << ' ' << y/(g1 - g2);
			}
		}
		else cout << 0;
	}else{
		if((ab <= 0 && cd <= 0)){
			cout << 1 << "\n";
			cout << fixed;
			cout.precision(9);
			cout << x/(g1-g2) << ' ' << y/(g1-g2);
		}
		else cout << 0;
	}
}