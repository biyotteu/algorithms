#include <bits/stdc++.h>

using namespace std;

int n,h,res = 1e9,cnt;
vector<int> up,down;
int main(){
	scanf("%d %d",&n,&h);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(i%2 == 0) down.push_back(x);
		else up.push_back(x);
	}
	sort(down.begin(),down.end());
	sort(up.begin(),up.end());
	for(int i=1;i<=h;i++){
		int a = down.end() - upper_bound(down.begin(),down.end(),i);
		int b = up.end() - lower_bound(up.begin(),up.end(),h-i);
		if(res > a+b){
			res = a+b;
			cnt = 0;
		}
		if(res == a+b) cnt++;
	}
	printf("%d %d",res,cnt);
}