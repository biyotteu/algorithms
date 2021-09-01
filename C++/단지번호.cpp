#include <bits/stdc++.h>

using namespace std;

int n, d[30][30], visit[30][30], cnt;
vector<int> res;
void dfs(int x, int y)
{
    if (visit[x][y])
        return;
    int X[4] = {1, 0, -1, 0};
    int Y[4] = {0, 1, 0, -1};
    visit[x][y] = 1;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        if (d[x + X[i]][y + Y[i]])
            dfs(x + X[i], y + Y[i]);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char x;
            scanf(" %c", &x);
            d[i][j] = x - 48;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] && !visit[i][j])
            {
                cnt = 0;
                dfs(i, j);
                res.push_back(cnt);
            }
        }
    printf("%d\n", res.size());
    sort(res.begin(), res.end());
    for (auto i : res)
        printf("%d\n", i);
}