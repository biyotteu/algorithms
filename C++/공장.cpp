#include <bits/stdc++.h>

using namespace std;

int n,h;
long long res;
map<int,int> m;
vector<int> num,tree;
void update(int x,int v){
	x += h;
	tree[x] += v;
	x/=2;
	while(x){
		tree[x] = tree[x*2] + tree[x*2+1];
		x/=2;
	}
}
int sum(int x,int y){
	x+=h,y+=h;
	int ret = 0;
	while(x<=y){
		if(x%2) ret += tree[x++];
		if(y%2 == 0) ret += tree[y--];
		x/=2;
		y/=2;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(h = 1;h<n;h*=2);
	tree.resize(h*2+1);
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		num.push_back(x);
	}
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		m[x] = i; 
	}
	for(int i=1;i<=num.size();i++){
		res += sum(m[num[i-1]]+1,n);
		update(m[num[i-1]],1);
	}
	cout << res;
}