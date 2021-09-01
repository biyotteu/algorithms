#include <bits/stdc++.h>
 
using namespace std;
 
int n;
vector<int> graph[100005];
int dist[100005],inQ[100005],cost[100005];
int spfa()
{
    queue<int> Q;
    for(int i=1;i<=n;i++)
        inQ[i]=0;
    Q.push(1);
    inQ[1]=1;
    dist[1]=cost[1];
    while(!Q.empty())
    {
        int cur = Q.front();
        inQ[cur]=0;
        Q.pop();
        for(auto i:graph[cur])
        {
            if(dist[i]<dist[cur]+cost[i])
            {
               dist[i]=dist[cur]+cost[i];
               if(!inQ[i])
               {
                   inQ[i]=1;
                   Q.push(i);
               }
            }
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",dist[i]);
}
int main()
{
   scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&cost[i]);
    for(int i=1;i<=n;i++) cost[i] = -cost[i];
    for(int i=0;i<n-1;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    spfa();
}