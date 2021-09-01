#include <bits/stdc++.h>

using namespace std;

struct info{
	string name;
	int g,m,e;
	bool operator<(const info a){
		if(a.g == g){
			if(a.e == e){
				if(a.m == m){
					return name < a.name; 
				}else return m > a.m;
			}else return e < a.e;
		}else return g > a.g;
	}
};
int main(){
	vector<info> st;
	int n;
	cin >> n;
	while(n--){
		info cur;
		cin >> cur.name >> cur.g >> cur.e >> cur.m;
		st.push_back(cur);
	}
	sort(st.begin(),st.end());
	for(auto i:st) cout << i.name << "\n";

}