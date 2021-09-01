#include <bits/stdc++.h>

using namespace std;

struct info{
	int co;
	vector<int> ti;
	bool operator<(info a){
		return co > a.co;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	vector<info> d(n*n);
	for(int i=0;i<n*n;i++){
		int x,y;
		cin >> x >> y;
		d[i].co = x;
		while(y--){
			int z;
			cin >> z;
			d[i].ti.push_back(z);
		}
	}
	sort(d.begin(),d.end());
	long long res = 0;
	set<int> s;
	for(int i=0;i<n*n;i++){
		for(int j=0;j<d[i].ti.size();j++){
			if(s.find(d[i].ti[j]) == s.end()){
				s.insert(d[i].ti[j]);
				res += d[i].co;
			}
		}
	}
	cout << res;
}