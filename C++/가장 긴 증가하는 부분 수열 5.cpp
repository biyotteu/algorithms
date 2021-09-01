#include <bits/stdc++.h>

using namespace std;
using pp = pair<int,int>;

vector<pp> num;
int n,pos[1000005],a[1000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		a[i] = x;
		if(num.empty() || num.back().first < x){
			if(!num.empty()) pos[i] = num.back().second;
			num.push_back({x,i});
		} 
		else{
			auto k = lower_bound(num.begin(),num.end(),make_pair(x,0));
			*k = {x,i};
			pos[i] = num[k - num.begin() - 1].second;
		}
	}
	cout << num.size() << "\n";
	vector<int> res;
	int p = num.back().second;

	for(int i=0;i<num.size();i++){
		res.push_back(p);
		p = pos[p];
	}
	for(int i=res.size()-1;i>=0;i--){
		cout << a[res[i]] << ' ';
	}
}