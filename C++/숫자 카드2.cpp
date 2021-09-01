#include <bits/stdc++.h>

using namespace std;

vector<int> num;
int n,m;
int main(){
	scanf("%d",&n);
	num.resize(n);
	for(int i=0;i<n;i++) scanf("%d",&num[i]);
	sort(num.begin(),num.end());
	scanf("%d",&m);
	while(m--){
		int x;
		scanf("%d",&x);
		printf("%d ",upper_bound(num.begin(),num.end(),x) - lower_bound(num.begin(),num.end(),x));
	}
}