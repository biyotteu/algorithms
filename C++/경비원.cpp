#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y,z;
};
int n,m,_next[5]={0,2,1,4,3},res;
vector<info> p;
int main(){
	scanf("%d %d",&n,&m);
	int t;
	scanf("%d",&t);
	t++;
	while(t--){
		int x,y;
		scanf("%d %d",&x,&y);
		if(x == 1) p.push_back({0,y,x});
		if(x == 2) p.push_back({m,y,x});
		if(x == 3) p.push_back({y,0,x});
		if(x == 4) p.push_back({y,n,x});
	}
	info s = p.back();
	p.pop_back();
	for(auto i:p){
		if(i.z == s.z){
			if(i.z == 1 || i.z == 2) res += (int)abs(i.y-s.y);
			if(i.z == 3 || i.z == 4) res += (int)abs(i.x-s.x);
		}
		else if(_next[i.z] == s.z){
			if(i.z == 1 || i.z == 2) res += m+min((i.y+s.y),2*n-(i.y+s.y));
			if(i.z == 3 || i.z == 4) res += n+min((i.x+s.x),2*m-(i.x+s.x));
		}
		else{
			res += (abs(i.x-s.x) + abs(i.y-s.y));
		}
	}
	printf("%d",res);
}