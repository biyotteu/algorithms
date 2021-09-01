#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> num;
vector<int> tree;
int n,k;
int update(int x,int v){
	int idx = k+x;
	tree[idx] = v;
	idx /= 2;
	while(idx){
		tree[idx] = tree[idx*2] + tree[idx*2+1];
		idx/=2;
	}
}
int sum(int x,int y){
	int xi = k+x,yi = k+y;
	int res = 0;
	while(xi<=yi){
		if(xi%2 == 1) res += tree[xi++];
		if(yi%2 == 0) res += tree[yi--];
		xi/=2,yi/=2;
	}
	return res;
}
int main(){
	scanf("%d",&n);
	for(k=1;k<n;k*=2);
	tree.resize(k*2+1);
	for(int i=0;i<n;i++) update(i,1);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		num.push_back({x,i});
	}
	sort(num.begin(),num.end());
	int start = 0,end = n-1;
	for(int i=0;i<n;i++){
		if(i%2==0){
			printf("%d\n",sum(0,num[start].second-1));
			update(num[start].second,0);
			start++;
		}
		else{
			printf("%d\n",sum(num[end].second+1,n-1));
			update(num[end].second,0);
			end--;
		}
	}
}