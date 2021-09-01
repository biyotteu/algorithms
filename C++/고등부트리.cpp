#include <bits/stdc++.h>
#define MM 200005

using namespace std;

int n,q,ver[MM],color[MM],visit[MM];
vector<int> gr[MM];
void f(int st,int en,int nw,int nx){
	color[st] = nx;
	for(int i:gr[st]) if(i!=en && color[i] == nw) f(i,en,nw,nx);
}
bool lg(int x,int y,int cnt){
	queue<pair<int,int>> Q;
	Q.push({x,1});
	Q.push({y,0});
	visit[x] = visit[y] = cnt;
	while(!Q.empty()){
		int size = Q.size();
		while(size--){
			pair<int,int> cur = Q.front();Q.pop();
			bool cmp = true;
			for(int i:gr[cur.first]){
				if(visit[i] != cnt && color[cur.first] == color[i]){
					if((cur.second == 1 && i!=y) || (cur.second == 0 && i!=x)){
						visit[i] = cnt;
						Q.push({i,cur.second});
						cmp = false;
					}
				}
			}
			if(cmp) return cur.second;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i=2;i<=n;i++){
		cin >> ver[i];
		gr[i].push_back(ver[i]);
		gr[ver[i]].push_back(i);
	}
	for(int i=0;i<q;i++){
		int x,y,z;
		cin >> x >> y >> z;
		cout << (color[x] == color[y] ? "YES\n" : "NO\n");
		if(!z) continue;
		if(color[x] == color[y]) lg(x,ver[x],i) ? f(x,ver[x],color[x],i+1) : f(ver[x],x,color[ver[x]],i+1);
		else lg(y,ver[y],i) ? f(y,ver[y],color[y],i+1) : f(ver[y],y,color[ver[y]],i+1);
	}
}