#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	vector<int> num;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		num.push_back(x);
	}
	sort(num.begin(),num.end());
	double res = (num[0]+num[1])/2.0;
	for(int i=2;i<n;i++) res = (res+num[i])/2.0;
	printf("%f",res);
}