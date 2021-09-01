#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	long long int sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) if(n%i==0) sum+=i;
	printf("%lld",sum*5-24);
}