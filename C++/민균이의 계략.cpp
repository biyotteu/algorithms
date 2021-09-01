#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> num;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(num.empty()) num.push_back(x);
		else if(num.back() < x) num.push_back(x);
		else{
			auto idx = lower_bound(num.begin(),num.end(),x);
			*idx = x;
		}
	}
	printf("%d",num.size());
}