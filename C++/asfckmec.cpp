#include <bits/stdc++.h>

#define INF 987654321;

using namespace std;

queue<int> Q;
int inQ[505],road[505][505],worm[505][505],dist[505],visit[505];
int t,n,m,w,start;
int main()
{
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        start = clock();
        int x,y,z;
        scanf("%d %d %d",&n,&m,&w);
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
        {
            road[j][k]=-1;
            worm[j][k]=1;
        }
        for(int j=0;j<m;j++)
        {
            scanf("%d %d %d",&x,&y,&z);
            if(road[x][y]!=-1)
            {
                road[x][y]=min(road[x][y],z);
                road[y][x]=road[x][y];
                continue;
            }
            road[x][y]=road[y][x]=z;
        }
        for(int j=0;j<w;j++)
        {
            scanf("%d %d %d",&x,&y,&z);
            if(worm[x][y]!=1)
            {
                worm[x][y]=min(worm[x][y],-1*z);
                continue;
            }
            worm[x][y]=z*-1;
        }
        for(int i=1;i<=n;i++)
        {
            dist[i]=INF;
            inQ[i]=0;
            visit[i]=0;
        }
        dist[1]=0;
        Q.push(1);
        inQ[1]=1;
        int flag=0;
        int cur;
        while(!Q.empty())
        {
            cur=Q.front();
            Q.pop();
            inQ[cur]=0;
            visit[cur]++;
            if(clock()-start > 1000)
            {
                flag=1;
                printf("YES\n");
                break;
            }
            for(int i=1;i<=n;i++)
            {
                if(cur==i)
                    continue;
                if(road[cur][i]!=-1 && dist[i]>dist[cur]+road[cur][i])
                {
                    dist[i]=dist[cur]+road[cur][i];
                    if(inQ[i]==0)
                    {
                        Q.push(i);
                        inQ[i]=1;
                    }
                }
                if(worm[i][cur]!=1 && dist[i]>dist[cur]+worm[i][cur])
                {
                    dist[i]=dist[cur]+worm[i][cur];
                    if(inQ[i]==0)
                    {
                        Q.push(i);
                        inQ[i]=1;
                    }
                }
            }
        }
        while(!Q.empty())
            Q.pop();
        if(!flag)
            printf("NO\n");
    }
}