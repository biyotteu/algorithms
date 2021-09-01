#include <bits/stdc++.h>

using namespace std;
using pp = pair<int,int>;

int n,mx,res;
vector<int> a,seg,lazy;
vector<pp> post;
map<int,int> mp;
void unlazy(int node,int start,int end){
	if(!lazy[node]) return;
	seg[node] = lazy[node]*(end-start+1);
	if(start!=end)
		lazy[node*2] = lazy[node*2+1] = lazy[node];
	lazy[node] = 0;
}
void update(int node,int start,int end,int x,int y,int v){
	unlazy(node,start,end);
	if(start > y || end < x) return;
	if(x <= start && end <= y){
		lazy[node] = v;
		unlazy(node,start,end);
		return;
	}
	update(node*2,start,((start+end)>>1),x,y,v);
	update(node*2+1,((start+end)>>1)+1,end,x,y,v);
	seg[node] = seg[node*2] + seg[node*2+1];
}
int sum(int node,int start,int end,int x,int y){
	unlazy(node,start,end);
	if(end < x || start > y) return 0;
	if(x <= start && end <= y) return seg[node];
	return sum(node*2,start,((start+end)>>1),x,y) + sum(node*2+1,((start+end)>>1)+1,end,x,y);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		a.push_back(x);
		a.push_back(y);
		post.push_back({x,y});
	}
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	mx = a.back();
	for(int i=0;i<a.size();i++) mp[a[i]] = i;
	mx = mp[mx];
	int size = (int)ceil(log2(mx));
	seg.resize((1<<(size+1)));
	lazy.resize((1<<(size+1)));
	for(int i=0;i<n;i++){
		pp cur;
		cur.first = mp[post[i].first];
		cur.second = mp[post[i].second];
		post[i] = cur;
	}
	for(int i=n-1;i>=0;i--){
		if(sum(1,0,mx,post[i].first,post[i].second) < 1-post[i].first+post[i].second){
			res++;
			update(1,0,mx,post[i].first,post[i].second,1);
		}
	}
	cout << res;
}