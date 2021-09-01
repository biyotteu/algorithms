#include <bits/stdc++.h>

using namespace std;
using ddpp = pair<double,double>;
using diipp = pair<double,pair<int,int>>;

vector<ddpp> pos;
priority_queue<diipp,vector<diipp>,greater<diipp>> Q;
double res;
int n,parent[105];
double dist(ddpp a,ddpp b){
	return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}
int _find(int v){
	if(v == parent[v]) return v;
	return parent[v] = _find(parent[v]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) parent[i] = i;
	for(int i=1;i<=n;i++){
		ddpp x;
		scanf("%lf %lf",&x.first,&x.second);
		pos.push_back(x);
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			Q.push({dist(pos[i-1],pos[j-1]),{i,j}});
	while((int)Q.size()){
		diipp cur = Q.top();
		Q.pop();
		int a = _find(cur.second.first);
		int b = _find(cur.second.second);
		if(a!=b){
			res+=cur.first;
			parent[a] = b;
		}
	}
	printf("%.2lf",res);
}