#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int n,m,parent[10005];
long long int res1,res2;
struct info{
	int x,y;
	ll z;
	info(){}
	info(int a,int b,ll c){
		x = a, y = b, z = c;
	}
	bool operator<(info A)const{
		return A.z < z;
	}
};
int _find(int v){
	if(parent[v] == v) return v;
	return parent[v] = _find(parent[v]);
}
int _union(int a,int b){
	a = _find(a);
	b = _find(b);
	if(a == b) return 0;
	parent[a] = b;
	return 1;
}
vector<info> num;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) parent[i] = i;
	for(int i=0;i<m+1;i++){
		int a,b;
		ll c;
		scanf("%d %d %lld",&a,&b,&c);
		num.push_back(info(a,b,!c));
	}
	sort(num.begin(),num.end());
	for(int i=0;i<=n;i++) parent[i] = i;
	for(int i=0;i<num.size();i++) if(_union(num[i].x,num[i].y)) res1 += num[i].z; 
	for(int i=0;i<=n;i++) parent[i] = i;
	for(int i=num.size()-1;i>=0;i--) if(_union(num[i].x,num[i].y)) res2 += num[i].z;
	printf("%lld",res1*res1 - res2*res2);
}