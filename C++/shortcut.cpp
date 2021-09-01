#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y;
};
int n,m,t;
vector<info> graph[10005];
int main(){
	ifstream ifn("shortcut.in");
	ofstream ofn("shortcut.out");
	ifn >> n >> m >> t;
	for(int i=0;i<n;i++){
		int x,y,z;
		cin >> x >> y >> z;
		graph[x].push_back({y,z});
		graph[y].push_back({x,z});
	}
	ifn.close();
	ofn.close();
	return 0;
}
