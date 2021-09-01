#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> p;
vector<int> v;
int n,m,cnt[1005],res;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		p.push_back({x,y});
	}
	sort(p.rbegin(),p.rend());
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v.push_back(x);
		cnt[x] += y;
	}
	sort(v.rbegin(),v.rend());
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if((p[i].first<=v[j] && v[j] <= p[i].second)&&cnt[v[j]] > 0){
				res++;
				cnt[v[j]]--;
				break;
			}
		}
	}
	printf("%d",res);
}