#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y;
	info(){}
	info(int a,int b){
		x = a,y=b;
	}
	bool operator<(info A)const{
		if(A.x == x) return A.y < y;
		else return A.x > x;
	}
};
bool cmp(info A,info B){
	if(A.y == B.y) return A.x < B.x;
	return A.y > B.y;
}
int n,h;
vector<info> sea;
vector<int> tree,B;
void update(int x,int v){
	x += h;
	tree[x] = v;
	x >>= 1;
	while(x){
		tree[x] = tree[x*2] + tree[x*2+1];
		x >>= 1;
	}
}
long long int sum(int x,int y){
	x += h, y += h;
	long long int res = 0;
	while(x<=y){
		if(x%2 == 1) res += tree[x++];
		if(y%2 == 0) res += tree[y--];
		x >>= 1,y >>= 1;
	}
	return res;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(h=1;h<n;h*=2);
		tree.resize(h*2+1);
		for(int i=0;i<n;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			sea.push_back(info(x,y));
		}
		sort(sea.begin(),sea.end(),cmp);
		for(int i=0;i<n;i++) sea[i].y = n-1-i;
		sort(sea.begin(),sea.end());
	    long long int res = 0;
		for(int i=0;i<n;i++){
			res += sum(sea[i].y+1,n-1);
			update(sea[i].y,1);
		}
		printf("%lld\n",res);
		sea.clear();
		tree.clear();
	}
}