#include <bits/stdc++.h>

using namespace std;

int n,t,g,visit[100000];
queue<pair<int,int>> Q;	
int main(){
	cin >> n >> t >> g;
	Q.push({n,0});
	memset(visit,-1,sizeof(visit));
	while(!Q.empty()){
		pair<int,int> cur = Q.front();
		Q.pop();
		if(cur.second > t || visit[cur.first]!=-1 && visit[cur.first] <= cur.second) continue;
		visit[cur.first] = cur.second;
		if(cur.first*2 <= 99999){
			int ret = cur.first*2;
			for(int i=1;i<=100000;i*=10){
				if(i > ret){
					ret -= (i/10);
					break;
				}
			}
			Q.push({ret,cur.second+1});
		}
		if(cur.first + 1 <= 99999) Q.push({cur.first+1,cur.second+1});
	}
	if(visit[g] == -1){
		cout << "ANG";
		return 0;
	}
	cout << visit[g];
}