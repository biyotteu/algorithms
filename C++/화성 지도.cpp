#include <bits/stdc++.h>
#define MX 30000
using namespace std;

struct info{
	int x,y,y1,v;
	bool operator<(info A){
		return x < A.x;
	}
};
vector<info> dd;
int n,last,seg[MX*5],cnt[MX*5],res;
void update(int node,int start,int end,int x,int y,int v){
	if(end < x || start > y) return ;
	if(x <= start && end <= y) cnt[node] += v;
	else{
		int mid = (start+end)>>1;
		update(node*2,start,mid,x,y,v);
		update(node*2+1,mid+1,end,x,y,v);
	}
	if(cnt[node]) seg[node] = end-start+1;
	else{
		if(x == y) seg[node] = 0;
		seg[node] = seg[node*2] + seg[node*2+1];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++){
		int x,x1,y,y1;
		cin >> x >> y >> x1 >> y1;
		dd.push_back({x,y,y1,1});
		dd.push_back({x1,y,y1,-1});
	}
	sort(dd.begin(),dd.end());
	last = dd[0].x;
	update(1,0,MX,dd[0].y,dd[0].y1-1,1);
	for(int i=1;i<dd.size();i++){
		int dist = dd[i].x - last;
		res += dist*seg[1];
		update(1,0,MX,dd[i].y,dd[i].y1-1,dd[i].v);
		last = dd[i].x;
	}
	cout << res;
}