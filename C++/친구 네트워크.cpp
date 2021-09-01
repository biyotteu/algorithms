#include <bits/stdc++.h>

using namespace std;

map<string,string> parent;
map<string,int> team;
string _find(string v){
	if(parent[v].compare(v) == 0) return v;
	return parent[v] = _find(parent[v]);
}
int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		parent.clear();
		cin >> n;
		set<string> A;
		vector<pair<string,string>> B;
		for(int i=0;i<n;i++){
			string x,y;
			cin >> x >> y;
			A.insert(x);
			A.insert(y);
			B.push_back({x,y});
		}
		for(auto i:A) parent[i] = i, team[i] = 1;
		for(auto i:B){
			string a = _find(i.first), b = _find(i.second);
			if(a.compare(b) == 0){
				cout << team[a] << "\n";
				continue;
			}else{
				parent[a] = b;
				team[b] = team[b] + team[a];
				team[a] = 0;
				cout << team[b] << "\n";
			}
		}
	}
}