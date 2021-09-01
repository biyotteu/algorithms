#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> num,pos,res,ret;
void trace(int v,int cnt){
	if(v < 0) return;
	if(pos[v] == cnt){ 
		res.push_back(ret[v]);
		trace(v-1,cnt-1);
	}
	else trace(v-1,cnt);
}
int main(){
	scanf("%d",&n);
	pos.resize(n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		ret.push_back(x);
		if(num.empty() || num.back() < x){
			num.push_back(x);
			pos[i] = num.size() - 1;
		}else{
			auto k = lower_bound(num.begin(),num.end(),x);
			*k = x;
			pos[i] = k - num.begin();
		}
	}
	trace(n-1,num.size()-1);
	sort(res.begin(),res.end());
	printf("%d\n",res.size());
	for(auto i:res) printf("%d ",i);
}