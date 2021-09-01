#include <bits/stdc++.h>
#define INF (1<<29)
using namespace std;

vector<int> mintree,maxtree;
int n,k,h;
void update(int x,int v){
	int idx = h+x;
	mintree[idx] = v;
	maxtree[idx] = v;
	idx/=2;
	while(idx){
		mintree[idx] = min(mintree[idx*2],mintree[idx*2+1]);
		maxtree[idx] = max(maxtree[idx*2],maxtree[idx*2+1]);
		idx/=2; 
	}
}
int getmin(int x,int y){
	x += h;
	y += h;
	int res = INF;
	while(x<=y){
		if(x%2 == 1) res = min(res,mintree[x++]);
		if(y%2 == 0) res = min(res,mintree[y--]);
		x/=2,y/=2;
	}
	return res;
}
int getmax(int x,int y){
	x += h;
	y += h;
	int res = 0;
	while(x<=y){
		if(x%2 == 1) res = max(res,maxtree[x++]);
		if(y%2 == 0) res = max(res,maxtree[y--]);
		x/=2,y/=2;
	}
	return res;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		for(h=1;h<n;h*=2);
		mintree.resize(h*2+1,INF);
		maxtree.resize(h*2+1);
		for(int i=0;i<n;i++) update(i,i);
		for(int i=0;i<k;i++){
			int q,a,b;
			scanf("%d %d %d",&q,&a,&b);
			if(q){
				if(getmin(a,b) == a && getmax(a,b) == b) printf("YES\n");
				else printf("NO\n");
			}else{
				int A = mintree[h+a], B = mintree[h+b];
				update(a,B);
				update(b,A);
			}
		}
		mintree.clear();
		maxtree.clear();
	}
}