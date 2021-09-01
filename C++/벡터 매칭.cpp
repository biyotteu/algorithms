#include <bits/stdc++.h>

using namespace std;


vector<pair<int,int>> v;
int xs,ys,n;
long long f(int ret,int k){
	if(k == n/2){

	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		v.clear();
		xs = ys = 0;
		cin >> n;
		for(int i=0;i<n;i++){
			int x,y;
			cin >> x >> y;
			v.push_back({x,y});
			xs += x,ys += y;
		}
		cout << sqrt(min(f(0,1),f()));
	}
}