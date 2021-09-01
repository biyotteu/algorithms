#include <bits/stdc++.h>

using namespace std;

int edge[3005][3005], cost[3005][3005], sum[3005], DP[3005], idx[3005];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        while (1)
        {
            int x;
            scanf("%d", &x);
            if (x == 0) break;
            edge[min(i, x)][max(i, x)] = 1;
        }
    }
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + i - 1;
    for (int i = 1; i <= n; i++) cost[i - 1][i] = edge[i - 1][i];
    for (int i = 2; i < n; i++) {
        for (int j = 1; j + i <= n; j++) {
            cost[j][j + i] = cost[j + 1][j + i] + cost[j][j + i - 1] - cost[j + 1][j + i - 1] + edge[j][j + i];
        }
    }
    for (int i = 1; i <= n; i++) {
        DP[i] = 1E9;
        for (int j = 0; j < i; j++) {
            int cur = DP[j] + cost[1][i] - cost[1][j] - cost[j + 1][i] + sum[i - j] - cost[j + 1][i];
            if (DP[i] > cur) {
                DP[i] = cur;
                idx[i] = i - j;
            }
        }
    }
    printf("%d\n", DP[n]);
    vector<int> res;
    while(n){
        res.push_back(idx[n]);
        n-=idx[n];
    }
    printf("%d",res.size());
    for(int i = res.size()-1;i>=0;i--)
        printf(" %d",res[i]);
}
