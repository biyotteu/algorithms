#include <bits/stdc++.h>

using namespace std;

int n;
map<string,string> parent;
map<string,int> cnt;
string _find(string v){
	if(parent[v].compare(v) == 0) return v;
	return parent[v] = _find(parent[v]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		parent.clear();
		cin >> n;
		while(n--){
			string a,b;
			cin >> a >> b;
			if(parent[a].compare("") == 0){
				parent[a] = a;
				cnt[a] = 1;
			} 
			if(parent[b].compare("") == 0){
				parent[b] = b;
				cnt[b] = 1;
			}
			a = _find(a), b = _find(b);
			if(a.compare(b) == 0){
				cout << cnt[a] << "\n";
			}else{
				parent[b] = a;
				cnt[a] = cnt[a] + cnt[b];
				cnt[b] = 0;
				cout << cnt[a] <<"\n";
			}
		}
	}
}