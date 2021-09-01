#include <bits/stdc++.h>

using namespace std;

int n,m,q,visit[500005],num[500005],parent[500005];
long long res,sum[500005];
set<long long> S;
vector<pair<int,int>> gr;
vector<pair<int,pair<int,int>>> Q;
int _find(int v){
	if(v == parent[v]) return v;
	return parent[v] = _find(parent[v]);	
}
int main(){
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		Q.push_back({2,{i,x}});
		sum[i] = x;
		num[i] = x;
		parent[i] = i;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		gr.push_back({x,y});
	}
	for(int i=0;i<q;i++){
		char x;
		int y,z;
		scanf(" %c",&x);
		if(x == 'D'){
			scanf(" %d",&y);
			visit[y] = 1;
			Q.push_back({1,{y-1,0}});
		}
		if(x == 'P'){
			scanf(" %d %d",&y,&z);
			sum[y] = z;
			Q.push_back({2,{y,num[y]}});
			num[y] = z;
		}
	}
	for(int i=1;i<=n;i++)	S.insert(sum[i]);
	for(int i=0;i<m;i++){
		if(visit[i+1]) continue;
		int a = _find(gr[i].first);
		int b = _find(gr[i].second);
		if(a == b) continue;
		if(S.find(sum[a]) != S.end()) S.erase(S.find(sum[a]));
		if(S.find(sum[b]) != S.end()) S.erase(S.find(sum[b]));
		parent[a] = b;
		sum[b] += sum[a];
		sum[a] = 0;
		S.insert(sum[b]);
	}
	vector<long long> result;
	result.push_back(*S.rbegin());
	for(int i=Q.size()-1;i>=0;i--){
		pair<int,pair<int,int>> cur = Q[i];
		if(cur.first == 1){
			pair<int,int> v = gr[cur.second.first];
			int a = _find(v.first);
			int b = _find(v.second);
			if(a != b){ 
				if(S.find(sum[a]) != S.end()) S.erase(S.find(sum[a]));
				if(S.find(sum[b]) != S.end()) S.erase(S.find(sum[b]));
				parent[a] = b;
				sum[b] += sum[a];
				sum[a] = 0;
				S.insert(sum[b]);
			}
		}else{
			int idx = cur.second.first;
			int a = _find(idx);
			if(S.find(sum[a]) != S.end()) S.erase(S.find(sum[a]));
			sum[a] += (cur.second.second-num[idx]);
			S.insert(sum[a]);
			num[idx] = cur.second.second;
		}
		result.push_back(*S.rbegin());
	}
	n+=1;
	while(n--) result.pop_back();
	while(result.size()){
		printf("%lld\n",result.back());
		result.pop_back();
	}
}