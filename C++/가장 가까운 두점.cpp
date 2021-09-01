#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y;
	bool operator<(info A)const{
		if(y == A.y) return x < A.x;
		return y < A.y;
	}
};

vector<info> node;
set<info> S;
int dist(info A,info B){
	return (A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y-B.y);
}
bool cmp(const info &A,const info &B){
	return A.x < B.x;
}
int main(){
	int n,d,cnt = 0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		node.push_back({x,y});
	}
	sort(node.begin(),node.end(),cmp);
	d = dist(node[0],node[1]);
	S.insert(node[0]);
	S.insert(node[1]);
	for(int i=2;i<n;i++){
		int cur = (int)sqrt((double)d) + 1;
		while(cnt<i){
			if((node[i].x - node[cnt].x) > cur){
				S.erase(node[cnt]);
				cnt++;
			}else break;
		}
		auto l = S.lower_bound({-100000,node[i].y-cur});
		auto r = S.upper_bound({100000,node[i].y+cur});
		for(auto j = l;j!=r;j++) d = min(d,dist(node[i],*j));
		S.insert(node[i]);
	}
	printf("%d",d);
}	