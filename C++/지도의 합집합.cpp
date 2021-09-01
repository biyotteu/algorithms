#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y,z;
	bool operator<(info A)const{
		return x<A.x;
	}
};
int n,tree[(1<<21)];
vector<info> ver;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	tree.resize();
	for(int i=0;i<n;i++){
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ver.push_back({x1,y1,0});
		ver.push_back({x1,y1,1});
	}
	sort(ver.begin(),ver.end());
}