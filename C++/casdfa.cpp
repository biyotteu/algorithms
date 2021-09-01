#include <bits/stdc++.h>
 
using namespace std;
 
int n,m,res;
int M[105][105];
int X[4],Y[4];
void dfs(int x,int y)
{
    M[x][y] = 0;
    for(int i=0;i<4;i++)
        if(M[x+X[i]][y+Y[i]]==-1)
            dfs(x+X[i],y+Y[i]);
}
int main()
{
    cin >> n >> m;
    X[0] = Y[1] = 1;
    X[2] = Y[3] = -1;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> M[i][j];
    while(++res)
    {
        bool flag = true;
        for(int i=0; i<=n+1; i++)
        for(int j=0; j<=m+1; j++)
        {
            if(M[i][j])
                flag = false;
            if(!M[i][j])
                M[i][j] = -1;
        }
        if(flag)
            break;
        dfs(0,0);
        for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(M[i][j] == 1)
            {
                int index = 0;
                for(int k=0;k<4;k++)
                    if(M[i+X[k]][j+Y[k]]==0)
                        index++;
                if(index>=2)
                    M[i][j] = -1;
            }
        }
        for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(M[i][j]==-1)
                M[i][j]=0;
    }
    cout << res-1;
}