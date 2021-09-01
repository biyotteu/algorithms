#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		char res[1000000];
		vector<pair<int,int>> p;
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++){
			int x;
			scanf("%d",&x);
			for(int k=3;k<=sqrt(x);k++){
				if(x%k == 0){
					p.push_back({x/k,i});
					p.push_back({k,i});
				} 
			}
		}
		sort(p.begin(),p.end());
		last = -1;
		int cnt = 65;
		for(auto i:p){
			if(last == i.first) res[i.second] = cnt;

		}
		for(int i=0)
	}
}