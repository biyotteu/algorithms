#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> num;
	int n;
	scanf("%d",&n);
	num.push_back(-(1<<29));
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(num.back() < x) num.push_back(x);
		else{
			auto idx = lower_bound(num.begin(),num.end(),x);
			*idx = x;
		}
	}
	printf("%d",num.size()-1);
}
