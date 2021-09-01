#include <bits/stdc++.h>

using namespace std;

int n,h;
long long int fro[100005],bac[100005],num[100005];
vector<int> tree;
void update(int x,int v){
	x += h;
	tree[x] += v;
	x >>= 1;
	while(x){
		tree[x] = tree[x*2] + tree[x*2+1];
		x >>= 1;
	}
}
long long int sum(int x,int y){
	x+=h,y+=h;
	long long int res = 0;
	while(x<=y){
		if(x%2) res += tree[x++];
		if(y%2 == 0) res += tree[y--];
		x >>= 1, y >>= 1;
	}
	return res;
}
int main(){
	scanf("%d",&n);
	for(h=1;h<n;h*=2);
	tree.resize(h*2+1);
	for(int i=0;i<n;i++) scanf("%lld",&num[i]);
	for(int i=n-1;i>=0;i--){
		fro[i] = sum(0,num[i]-2);
		update(num[i]-1,1);
	}
	tree.clear();
	tree.resize(h*2+1);
	for(int i=0;i<n;i++){
		bac[i] = sum(num[i],n-1);
		update(num[i]-1,1);
	}
	long long int res = 0;
	for(int i=0;i<n;i++) res += bac[i]*fro[i];
	printf("%lld",res);
}