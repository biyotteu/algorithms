#include <bits/stdc++.h>

using namespace std;

int n,c,m,s,res;
vector<pair<int,int>> truck[2005];
int _next[2005];
int main(){
	scanf("%d %d %d",&n,&c,&m);
	for(int i=0;i<m;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		truck[x].push_back({y,z});
	}
	for(int i=1;i<=n;i++) sort(truck[i].begin(),truck[i].end());
	for(int q=1;q<=n;q++){
		res += _next[q];
		c += _next[q];	
		_next[q] = 0;
		for(auto i:truck[q]){
			if(c > 0){ 
				int a = c;
				_next[i.first] += min(i.second,c);
				c -= min(i.second,c);
				i.second -= min(i.second,a);
			}
			int cmp = i.second;
			for(int j=n;j>i.first;j--){
				if(cmp == 0) break;
				if(_next[j]){
					int a = _next[j];
					_next[i.first] += min(cmp,_next[j]);
					_next[j] -= min(cmp,_next[j]);
					cmp -= min(cmp,a);
				}
			}
		}

	}
	printf("%d",res);
}