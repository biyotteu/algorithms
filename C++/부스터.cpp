//백준 15955번
//disjoint set문제
//각 체크 포인트의 정점을 x,y좌표를 기준으로 정렬하고 좌표 값의 차이를 구하여 저장한다.
//쿼리를 받아와 생명력을 기준으로 정렬한다
//저장해둔 좌표값의 차이가 퀴리에 생명력보다 적거나 같으면 두 정점을 병합해준다
//만약 같은 집합에 속해있다면 갈 수 있는 체크포인트가 된다.
#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y,z;
};
struct pos{
	int x,y,z,r;
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
bool zpos(const pos &A,const pos &B){
	return A.z < B.z;
}
bool rpos(const pos &A,const pos &B){
	return A.r < B.r;
}
int n,q,h,parent[250005];
vector<info> check,xs,ys;
vector<pos> Q;
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
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		check.push_back({x,y,i});
		parent[i] = i;
	}
	sort(check.begin(),check.end(),xcmp);
	for(int i=0;i<n-1;i++) ys.push_back({check[i].z,check[i+1].z,abs(check[i].x-check[i+1].x)});
	sort(check.begin(),check.end(),ycmp);
	for(int i=0;i<n-1;i++) xs.push_back({check[i].z,check[i+1].z,abs(check[i].y-check[i+1].y)});
	sort(xs.begin(),xs.end(),zcmp);
	sort(ys.begin(),ys.end(),zcmp);
	for(int i=0;i<q;i++){
		int x,y,z;
		cin >> x >> y >> z;
		Q.push_back({x-1,y-1,z,i});
	}
	sort(Q.begin(),Q.end(),zpos);
	int xidx = 0, yidx = 0;
	vector<pair<int,string>> res;
	for(int i=0;i<q;i++){
		while(xidx < n-1 && xs[xidx].z <= Q[i].z){
			_union(xs[xidx].x,xs[xidx].y);
			xidx++;
		}
		while(yidx < n-1 && ys[yidx].z <= Q[i].z){
			_union(ys[yidx].x,ys[yidx].y);
			yidx++;
		}
		if(_find(Q[i].x) == _find(Q[i].y)) res.push_back({Q[i].r,"YES\n"});
		else res.push_back({Q[i].r,"NO\n"});
	}
	sort(res.begin(),res.end());
	for(auto i:res) cout << i.second;
}