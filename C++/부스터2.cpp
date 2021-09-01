#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y,z;
};
bool xcmp(const info &A,const info &B){
	return A.x < B.x;
}
bool ycmp(const info &A,const info &B){
	return A.y < B.y;
}
bool zcmp(const info &A,const info &B){
	return A.z < B.z;
}
int n,q,h,parent[250005];
vector<info> check,Q,xs,ys;
int _find(int v){
	if(parent[v] == v) return v;
	return parent[v] = _find(parent[v]);
}
void _union(int a,int b){
	a = _find(a);
	b = _find(b);
	parent[a] = b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		parent[i] = i;
		int x,y;
		cin >> x >> y;
		check.push_back({x,y,i});
	}
	for(int i=1;i<=q;i++){
		int x,y,z;
		cin >> x >> y >> z;
		Q.push_back({x,y,z});
	}
	sort(check.begin(),check.end(),xcmp);
	for(int i=1;i<n;i++) ys.push_back({check[i].z,check[i-1].z,abs(check[i].y - check[i-1].y)});
	sort(check.begin(),check.end(),ycmp);
	for(int i=1;i<n;i++) xs.push_back({check[i].z,check[i-1].z,abs(check[i].x - check[i-1].x)});
	sort(Q.begin(),Q.end(),zcmp);
	int xidx = 0, yidx = 0;
	//for(auto i:xs) cout << i.x << " " << i.y << " " << i.z << endl;
	//	cout << "#####"<<endl;
	//	for(auto i:ys) cout << i.x << " " << i.y << " " << i.z << endl;
	for(auto i:Q){
		while(xidx<n-1 && xs[xidx].z <= i.z) _union(xs[xidx].x,xs[xidx].y),xidx++;
		while(yidx<n-1 && ys[yidx].z <= i.z) _union(ys[yidx].x,ys[yidx].y),yidx++;
		if(_find(i.x) == _find(i.y)) cout << "YES\n";
		else cout << "NO\n";
	}
}