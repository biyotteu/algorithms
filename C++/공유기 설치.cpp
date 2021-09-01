#include <bits/stdc++.h>

using namespace std;

int n,c,res;
vector<int> wifi;
bool f(int v){
	int last = wifi[0]+v,cnt = 1;
	for(int i=1;i<n;i++){
		if(wifi[i] >= last){
			last = wifi[i] + v;
			cnt++;
		}
		if(cnt == c) return true;
	}
	return false;
}
int main(){
	scanf("%d %d",&n,&c);
	wifi.resize(n);
	for(int i=0;i<n;i++) scanf("%d",&wifi[i]);
	sort(wifi.begin(),wifi.end());
	int l = 0, r = wifi.back() - wifi[0];
	while(l<=r){
		int mid = (l+r)/2;
		if(f(mid)){
		  l = mid+1;
		  res = max(res,mid);
		}
		else r = mid-1;
	}
	printf("%d",res);
}