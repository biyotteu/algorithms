#include <bits/stdc++.h>

using namespace std;

class info{
	int x,y,z;
	info(){}
	info(int a,int b,int c){
		x = a,y = b,z = c;
	}
}
int parent[200005],graph[200005];
vector<int> res;
vector<info> Qr;
int _find(int v)
{
	if(parent[v] == v) return v;
	return parent[v] = _find(parent[v]);
}
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++) parent[i]=i;
	for(int i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		parent[i]=x;
		graph[i]=x;
	}
	for(int i=0;i<q;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a==1)
		Qr.push_back(info(a,b,c)		);
	}
	for(int i=q-1;i>=0;i--){
		if(Qr[i].second){
			if(_find(Qr[i].first) == _find(Qr[i].second)) res.push_back(1);
			else res.push_back(0);
		}
		else{
			parent[_find(Qr[i].first)] = _find(graph[Qr[i].first]);
		}
	}
	while(!res.empty()){
		res.back() ? puts("YES") : puts("NO");
		res.pop_back();
	}
}