#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> ah;
int n;
long long int res;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		ah.push_back({x,y});
	}
	sort(ah.begin(),ah.end());
	int cur = ah[0].second;
	res += abs(ah[0].second - ah[0].first);
	for(int i=1;i<n;i++){
		if(cur > ah[i].second) continue;
		if(ah[i].first < cur){
			res += abs(ah[i].second - cur);
		}else{
			res += abs(ah[i].second - ah[i].first);
		}
		cur = ah[i].second;
	}
	printf("%lld",res);
}