	#include <bits/stdc++.h>

	using namespace std;

	int n,h;
	vector<int> tree,res;
	void update(int x,int v){
		x+=h;
		tree[x] = v;
		x/=2;
		while(x){
			tree[x] = tree[x*2] + tree[x*2+1];
			x/=2;
		}
	}
	int _find(int node,int start,int end,int v,int sum){
		if(start == end) return start;
		if(tree[node*2]+sum < v) return _find(node*2+1,(start+end)/2+1,end,v,sum+tree[node*2]);
		else return _find(node*2,start,(start+end)/2,v,sum);
	}
	int main(){
		scanf("%d",&n);
		for(h=1;h<n;h*=2);
		tree.resize(h*2+1);
		res.resize(n);
		for(int i=0;i<n;i++) update(i,1);
		for(int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			int k = _find(1,0,h-1,x+1,0);
			res[k] = i+1;
			update(k,0);
		}
		for(int i=0;i<n;i++) printf("%d\n",res[i]);
	}