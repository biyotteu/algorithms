#include <bits/stdc++.h>

using namespace std;

vector<pair<int,pair<int,int>>> p;
int con[105],cnt;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y,z;
		scanf("%d %d %d",&y,&z,&x);
		p.push_back({x,{y,z}});
	}
	sort(p.rbegin(),p.rend());
	for(auto i:p){
		if(cnt == 3) break;
		if(con[i.second.first] >= 2) continue;
		printf("%d %d\n",i.second.first,i.second.second);
		con[i.second.first]++;
		cnt++;
	}
}