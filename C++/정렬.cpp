#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,x;
	vector<int> num;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		num.push_back(x);
	}
	sort(num.begin(),num.end());
	for(auto i:num) printf("%d ",i);
}