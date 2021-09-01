#include <bits/stdc++.h>

using namespace std;

int n,m,cmp = 0,dep = -1;
vector<int> ob;
int main(){
	scanf("%d %d",&n,&m);
	int last = INT_MAX;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(x > last) x = last;
		last = x;
		ob.push_back(x);
	}
	sort(ob.begin(),ob.end());
	for(int i=0;i<m;i++){
		int x;
		scanf("%d",&x);
		if(cmp) continue;
		auto k = lower_bound(ob.begin(),ob.end(),x);
		if(k == ob.end()){
			cmp = 1;
			continue;
		}
		int now = n-(k-ob.begin());
		if(dep > now || dep == -1) dep = now;
		else{
			dep--;
			if(dep == 0) cmp =1;
		} 
	}
	if(cmp) puts("0");
	else printf("%d",dep);
}