#include <bits/stdc++.h>
using namespace std;
 
int n,m;
 
int neg(int x)
{
    if(x<=n)x+=n;
    else x-=n;
    return x;
}
int scnt;
int scc[20005];
vector<int> adj[20005];
vector<int> rev_adj[20005];
stack<int> stk;
void dfs(int cur)
{
    scc[cur]=-1;
    for(int i=0;i<adj[cur].size();++i){
        int nxt=adj[cur][i];
        if(scc[nxt]!=-1){
            dfs(nxt);
        }
    }
    stk.push(cur);
}
void dfs2(int cur)
{
    scc[cur]=scnt;
    for(int i=0;i<rev_adj[cur].size();++i){
        int nxt=rev_adj[cur][i];
        if(scc[nxt]==-1){
            dfs2(nxt);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        if(x<0)x=neg(-x);
        if(y<0)y=neg(-y);
        adj[neg(x)].push_back(y);
        adj[neg(y)].push_back(x);
        rev_adj[y].push_back(neg(x));
        rev_adj[x].push_back(neg(y));
    }
    for(int i=1;i<=2*n;++i){
        if(!scc[i])dfs(i);
    }
    while(!stk.empty()){
        int t=stk.top();
        stk.pop();
        if(scc[t]==-1){
            ++scnt;
            dfs2(t);
        }
    }
    bool valid=true;
    for(int i=1;i<=n;++i){
        if(scc[i]==scc[neg(i)]){
            valid=false;
            break;
        }
    }
    printf("%d\n",valid);
    if(valid){
        for(int i=1;i<=n;++i){
            printf("%d ",scc[i]>scc[neg(i)]);
        }
    }
}