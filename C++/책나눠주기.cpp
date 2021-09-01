#include <bits/stdc++.h>

using namespace std;

int n,m,visit[1005],fa[1005],fb[1005],res;
vector<vector<int>> book;
bool flow(int v){
	if(visit[v]) return false;
	visit[v] = 1;
	for(auto i:book[v]){
		if(fb[i] == 0 || flow(fb[i])){
			fb[i] = v;
			return true;
		}
	}
	return false; 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(fa,0,sizeof(fa));
		memset(fb,0,sizeof(fb));
		book.clear();
		book.resize(1005);
		res = 0;
		cin >> n >> m;
		for(int i=1;i<=m;i++){
			int x,y;
			cin >> x >> y;
			for(int j=x;j<=y;j++) book[i].push_back(j);
		}
		for(int i=1;i<=m;i++){
			memset(visit,0,sizeof(visit));
			if(flow(i)) res++;
		}
		cout << res << "\n";
	}
}

