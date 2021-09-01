#include <bits/stdc++.h>

using namespace std;

vector<int> l,r;
int DP[2005][2005];
int main()
{
    int n;
    cin >> n;
    l.push_back(0);
    r.push_back(0);
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        l.push_back(x);
    }
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        r.push_back(x);
    }
    int MAX = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            if(l[i]>r[j])
                DP[i][j] = max(DP[i][j],DP[i][j-1]+r[j]);
            DP[i][j] = max(DP[i][j],max(DP[i-1][j-1],DP[i-1][j]));
            MAX = max(MAX,DP[i][j]);
        }
    cout << MAX;
}
