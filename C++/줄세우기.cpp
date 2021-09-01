#include <bits/stdc++.h>

using namespace std;

vector<int> child;
int n;
main(){
	scanf("%d",&n);
	child.push_back(-(1<<29));
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(child.back()<x)
			child.push_back(x);
		else{
			auto it = lower_bound(child.begin(), child.end(), x);
        	*it = x;
		}
	}
	printf("%d",n-child.size()+1);
}