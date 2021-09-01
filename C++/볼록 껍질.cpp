#include <bits/stdc++.h>

using namespace std;
using pp = pair<int,int>;

int n;
vector<int> v;
int dist(pp a,pp b){
	return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}
int ccw(pp a,pp b,pp c){
	return (b.first - a.first)*(c.second - a.second) - (b.second - a.second)*(c.first - a.first);
}
bool cmp(pp x,pp y){
	int ra = ccw(v[0],x,y);
	if(ra == 0) return dist(v[0],x) < dist(v[0],y);
	else return (ra<0);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		v.push_back({x,y});
	}
	swap(v[0],*min_element(v.begin(),v.end()));
	sort(v+1,v.end(),cmp);
	vector<pp> res;
	res.push_back(v[0]);
	res.push_back(v[1]);
	for(int i=2;i<n;i++){
		while(res.size()>=2 && ccw(res[res.size()-2],res.back(),v[i]) >= 0) res.pop_back();
		res.push_back(v[i]);
	}
	cout << res.size();
}