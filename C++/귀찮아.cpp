#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	long long sum = 0, res = 0;
	vector<int> num;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		sum += x;
		num.push_back(x);
	}
	for(int i:num){
		sum -= i;
		res += i*sum;
	}
	printf("%lld",res);
}