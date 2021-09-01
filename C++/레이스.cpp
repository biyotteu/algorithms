#include <bits/stdc++.h>

using namespace std;

int n,m,k,res = 1e9;
vector<int> pos;
int f(int v){
	int last = pos[0] + v;
	for(int i=1;i<k;i++){

	}
}
int main(){
	scanf("%d %d %d"&n,&m,&k);
	pos.resize(k);
	for(int i=0;i<k;i++) scanf("%d",&pos[i]);
	int l = 0 , r = n;
	while(l<=r){
		int mid = (l+r)/2;
		if(f(mid)){
			res = min(res,mid);
			l = mid + 1;
		}
		else r = mid-1;
	}
	printf("%d",res);
}