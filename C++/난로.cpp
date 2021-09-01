#include <bits/stdc++.h>

using namespace std;

int n,k,res;
vector<int> T;
vector<int> sum;
int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		T.push_back(x);		
	}
	for(int i=1;i<n;i++)
		sum.push_back(T[i] - T[i-1]);
	sort(sum.begin(),sum.end());
	for(int i=0;i<n-k;i++) res += sum[i];
	res += k;
	printf("%d",res );
}