#include <bits/stdc++.h>

using namespace std;

int n,m,k,res;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q,truck[2005];
int main(){
	scanf("%d %d %d",&n,&k,&m);
	for(int i=0;i<m;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		truck[x].push({y,z});
	}
	for(int i=1;i<=n;i++){
		while(!Q.empty()){
			if(Q.top().first == i){
				res += Q.top().second;
				k+=Q.top().second;
				Q.pop();
			}
			else break;
		}
		while(!truck[i].empty() && k){
			pair<int,int> v = truck[i];
			Q.push({v.first,min(k,v.second)});
			k -= min(k,v.second);
		}
	}
}