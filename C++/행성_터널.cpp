#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y,z,idx;
	info(){}
	info(int a,int b,int c){
		x = a,y = b,z = c;
	}
	info(int a,int b,int c,int index){
		x = a,y = b,z = c,idx = index;
	}
	bool operator<(info A) const{
	    return z > A.z;
	}
};
bool cmpx(const info& A, const info& B){
	return A.x < B.x;
}
bool cmpy(const info& A, const info& B){
	return A.y < B.y;
}
bool cmpz(const info& A, const info& B){
	return A.z < B.z;
}
priority_queue<info> Q;
vector<info> num;
int n,parent[100005];
long long int res;
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
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		num.push_back(info(a,b,c,i));
	}
	sort(num.begin(),num.end(),cmpx);
	for(int i=0;i<num.size()-1;i++) Q.push(info(num[i].idx,num[i+1].idx,abs(num[i].x - num[i+1].x)));
	sort(num.begin(),num.end(),cmpy);
	for(int i=0;i<num.size()-1;i++) Q.push(info(num[i].idx,num[i+1].idx,abs(num[i].y - num[i+1].y)));
	sort(num.begin(),num.end(),cmpz);
	for(int i=0;i<num.size()-1;i++) Q.push(info(num[i].idx,num[i+1].idx,abs(num[i].z - num[i+1].z)));
	for(int i=0;i<n;i++) parent[i] = i;
	while(!Q.empty()){
		info cur = Q.top();
		Q.pop();
		if(_union(cur.x,cur.y)) res += cur.z;
	}
	printf("%d",res);
}
