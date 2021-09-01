#include <bits/stdc++.h>

using namespace std;
using pp = pair<int,int>;
int n;
vector<pp> sq;
bool cmp(const pp &A,const pp &B){
	if(A.second == B.second) return A.first < B.first;
	return A.second < B.second;
}
int main(){
	for(int i=0;i<n;i++){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		sq.push_back({x1,y1});
		sq.push_back({x2,y2});
	}
	sort(sq.begin(),sq.end(),cmp);
	pp last = sq[0];
	for(int i=1;i<sq.size();i++){
		
	}
}