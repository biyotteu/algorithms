#include <bits/stdc++.h>

using namespace std;

long long int road[100005];
int main()
{
    long long int mini = 1E9,res = 0,n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        scanf("%lld",&road[i]);
    for(int i=1;i<=n;i++){
        long long int x;
        scanf("%lld",&x);
        mini = min(mini,x);
        res += mini*road[i];
    }
    printf("%d",res);
}
