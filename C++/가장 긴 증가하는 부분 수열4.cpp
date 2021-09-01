#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	vector<int> res;
	scanf("%d",&n);
	while(n--){
		int x;
		scanf("%d",&x);
		if(res.empty() || res.back() < x) res.push_back(x);
		else{
			auto v = lower_bound(res.begin(),res.end(),x);
			(*v) = x;
		}
	}
	printf("%d\n",res.size());
	for(auto i:res) printf("%d ",i);
}