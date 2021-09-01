#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,res=0;
	scanf("%d",&n);
	vector<int> num(n);
	for(int i=0;i<n;i++) scanf("%d",&num[i]);
	sort(num.begin(),num.end());
	for(int i=0;i<n;i++)
		res = max(res,(n-i)*num[i]);
	printf("%d",res);
}