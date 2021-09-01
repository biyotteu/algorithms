#include <bits/stdc++.h>

using namespace std;
using pp = pair<int,int>;

int n,res;
vector<pp> station;
priority_queue<int> Q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		station.push_back({x,y});
	}
	sort(station.begin(),station.end());
	int start,end;
	cin >> end >> start;
	int i = 0;
	while(start < end){
		for(;i<n;i++) 
			if(station[i].first <= start) Q.push(station[i].second);
			else break;
		if(Q.size()){ 
			start += Q.top();
			Q.pop();
			res++;
		}
		else{
			cout << - 1;
			return 0;
		}
	}
	cout << res;
}