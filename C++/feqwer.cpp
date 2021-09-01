#include <bits/stdc++.h>

using namespace std;

int n,DP[505],num[505];
vector<pair<int,int>> a;
int main()
{
    cin >> n;
    int MAX=0;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin >> x >> y;
        a.push_back({x,y});
    }
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++)
        num[i+1]=a[i].second;
    for(int i=1;i<=n;i++)
    {
        DP[i]=1;
        for(int j=1;j<i;j++)
            if(num[j]<num[i])
                DP[i]=max(DP[i],DP[j]+1);
        MAX=max(DP[i],MAX);
    }
    cout << n-MAX;
}
