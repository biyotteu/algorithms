#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,res=0,l,r;
	vector<pair<int,int>> line;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		if(x > y) swap(x,y);
		line.push_back({x,y});
	}
	sort(line.begin(),line.end());
	l = line[0].first;
	r = line[0].second;
	res += (r-l);
	for(int i=0;i<n;i++){
		if(r < line[i].first){
			l = line[i].first;
			r = line[i].second;
			res += (r-l);
		}
		else if(line[i].first <= r && line[i].second > r){
			res += (line[i].second - r);
			r = line[i].second;
		}
	}
	printf("%d",res);
}
