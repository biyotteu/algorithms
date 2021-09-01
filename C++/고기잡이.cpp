#include <bits/stdc++.h>

using namespace std;

int n,l,m;
vector<pair<int,int>> fish;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l >> m;
	l/=2;
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		fish.push_back({x,y});
	}
	sort(fish.begin(),fish.end());
	for(int i=0;i<fish.size();i++){
		
	}
}