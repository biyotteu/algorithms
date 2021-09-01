#include <bits/stdc++.h>

using namespace std;

class ptree{
public:
	int s;
	vector<int> tree,v,index;
	ptree(int n,int m){
		int size = n+m+1;
		s = size;
		tree.resize(size+1);
		index.resize(n+1,0);
	}
	void update(int p,int value){
		while(p<=s){
			tree[p] += value;
			p += p&(-p);
		}
	}
	int sum(int p){
		int ret = 0;
		while(p>0){
			ret += tree[p];
			p-=p&(-p);
		}
		return ret;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		ptree movie(n,m);
		for(int i=1;i<=n;i++){
			movie.update(m+i,1);
			movie.index[i] = i+m;
		}
		for(int i=0;i<m;i++){
			int x;
			cin >> x;
			cout << movie.sum(movie.index[x]-1) << ' ';
			movie.update(movie.index[x],-1);
			movie.index[x] = m-i;
			movie.update(movie.index[x],1);
		}
		cout << "\n";
	}
}