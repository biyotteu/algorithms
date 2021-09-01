#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	vector<int> num(n);
	for(int i=0;i<n;i++) scanf("%d",&num[i]);
	sort(num.begin(),num.end());
	for(int i=1;i<n;i++) num[i] += num[i-1];
	int sum = 0;
	for(auto i:num) sum += i;
	printf("%d",sum);
}