#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y,z;
	bool operator<(info A) const{
		if(A.x == x){
			if(A.y == y) return z < A.z;
			return y < A.y;
		}
		return x < A.x;
	}
	bool operator==(info A) const{
		if(A.x == x && A.y == y && A.z == z) return true;
		else return false;
	}
};
int n,k,cnt = 1;
info co[1005];
int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		int x,y,z,r;
		scanf("%d %d %d %d",&r,&x,&y,&z);
		co[r] = {x,y,z};
	}
	for(int i=1;i<=n;i++){
		if(i == k) continue;
		if(co[i] == co[k]) continue;
		if(co[k] < co[i]) cnt++;
	}
	printf("%d",cnt);
}