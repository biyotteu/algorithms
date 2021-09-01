#include <bits/stdc++.h>

using namespace std;

int n,res,v;
vector<int> oc;
vector<pair<int,int>> gr;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	oc.resize(n+2);
	oc[0] = oc[n+1] = 1;
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		oc[i] = !x;
		if(x) gr.push_back({x,i});
	}
	sort(gr.begin(),gr.end());
	for(int i=1;i<=n;i++)
		if(oc[i-1]&&!oc[i]) v++;
	res = v;
	for(int i=0;i<gr.size();i++){
		pair<int,int> cur = gr[i];
		oc[cur.second] = 1;
		if(oc[cur.second-1] && oc[cur.second+1]) v--;
		else if(!oc[cur.second-1] && !oc[cur.second+1]) v++;
		if(gr.size()-1 == i || gr[i].first < gr[i+1].first)	res = max(v,res);
	}
	cout << res;
}