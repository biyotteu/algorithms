#include <bits/stdc++.h>

using namespace std;

int n,pos[500005];
vector<pair<int,int>> Q;
vector<int> ret,res;
void trace(int v,int cnt){
	if(v < 0) return;
	if(pos[v] == cnt){
		trace(v-1,cnt-1);
	}else{ 
		res.push_back(Q[v].first);
		trace(v-1,cnt);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		Q.push_back({x,y});
	}
	sort(Q.begin(),Q.end());
	for(int i=0;i<n;i++){
		if(ret.empty() || ret.back() < Q[i].second){
			ret.push_back(Q[i].second);
			pos[i] = ret.size() - 1;
		}else{
			auto k = lower_bound(ret.begin(),ret.end(),Q[i].second);
			*k = Q[i].second;
			pos[i] = k - ret.begin();
		}
	}
	trace(n-1,ret.size()-1);
	sort(res.begin(),res.end());
	printf("%d\n",res.size());
	for(auto i:res) printf("%d\n",i);
}