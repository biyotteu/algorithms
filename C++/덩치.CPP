#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> p;
vector<int> res;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		p.push_back({x,y});
	}
	for(int i=0;i<n;i++){
		int cnt = 1;
		for(int j=0;j<n;j++){
			if(i == j) continue;
			if(p[i].first < p[j].first && p[i].second < p[j].second) cnt++;
		}
		res.push_back(cnt);
	}
	for(auto i:res) printf("%d ",i);
}