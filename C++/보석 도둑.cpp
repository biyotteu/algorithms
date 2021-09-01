#include <bits/stdc++.h>

using namespace std;
using pp = pair<int,int>;

int n,k;
priority_queue<int> Q;
vector<int> bag;
vector<pp> jam;
long long int res;
	
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	bag.resize(k);
	for(int i=0;i<n;i++){
		int  x,y;
		cin >> x >> y;
		jam.push_back({x,y});
	}
	for(int i=0;i<k;i++) cin >> bag[i];
	sort(bag.begin(),bag.end());
	sort(jam.begin(),jam.end());
	for(int i=0,j=0;i<k;i++){
		for(;j<n;j++){
			if(jam[j].first > bag[i]) break;
			Q.push(jam[j].second);
		}
		if(Q.size()){
			res += Q.top();
			Q.pop();
		}
	}
	cout << res;
}