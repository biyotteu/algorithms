#include <bits/stdc++.h>

using namespace std;

vector<int> num;
int n;
int main(){
	scanf("%d",&n);
	while(n--){
		int x;
		scanf("%d",&x);
		num.push_back(x);
	}
	printf("%d",*max_element(num.begin(),num.end()) - *min_element(num.begin(),num.end()));
}