#include <bits/stdc++.h>

using namespace std;

int m,n,res;
vector<pair<int,pair<int,int>>> num;
vector<pair<int,int>> num1;
set<pair<int,int>> S[200005];
bool diff(int v,pair<int,int> p){
	auto cur = S[v].lower_bound(p);
	if(cur == S[v].begin()) return false;
	cur--;
	return (*cur).second < p.second;
}
void update(int v,pair<int,int> p){
	S[v].insert(p);
	auto cur = S[v].lower_bound(p);
	if(cur != S[v].begin()){
		cur--;
		if((*cur).second < p.second){
			cur++;
			S[v].erase(cur);
			return;
		}
	}
	while(1){
		cur = S[v].lower_bound(p);
		cur++;
		if(cur == S[v].end()) break;
		if((*cur).second < p.second) break;
		else S[v].erase(cur);
	}
}
int main(){
	scanf("%d %d",&m,&n);
	if(m == 2){
		num1.resize(n);
		for(int i=0;i<n;i++) scanf("%d",&num1[i].first);
		for(int i=0;i<n;i++) scanf("%d",&num1[i].second);
		sort(num1.begin(),num1.end());
	}
	else{
		num.resize(n);	
		for(int i=0;i<n;i++) scanf("%d",&num[i].first);
		for(int i=0;i<n;i++) scanf("%d",&num[i].second.first);
		for(int i=0;i<n;i++) scanf("%d",&num[i].second.second);
		sort(num.begin(),num.end());
		for(auto i:num) num1.push_back({i.second.first,i.second.second});
	}
	for(int i=0;i<n;i++){
		int l = 0, r = n-1;
		while(l<r){
			int mid = (l+r)/2+1;
			if(diff(mid,num1[i])) l = mid;
			else r = mid - 1;
		}
		update(l+1,num1[i]);
		res = max(l+1,res);
	}
	printf("%d",res);
}