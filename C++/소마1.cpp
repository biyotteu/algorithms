#include <bits/stdc++.h>

using namespace std;

int mp[15][15],idx[15][15],X[4] = {1,0,-1,0},Y[4] = {0,1,0,-1};
vector<int> edg[150];
int f(int st,int en){
    vector<int> dist(150,-1);
    priority_queue<pair<int,int>> q;
    dist[st] = 0;
    q.push({0,st});
    while(!q.empty()){
        pair<int,int> cur = q.top();q.pop();
        cur.first *= -1;
        if(cur.first > dist[cur.second]) continue;
        for(auto i:edg[cur.second]){
            if(dist[i] == -1 || dist[i] > dist[cur.second] + 1){
                dist[i] = dist[cur.second] + 1;
                q.push({-dist[i],i});
            }
        }
    }
    return dist[en];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int cnt = 1;
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++) idx[i][j] = cnt++;
    }
    int t;
    cin >> t;
    while(t--){
        int n,m,st,en,key;
        cin >> n >> m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> mp[i][j];
                if(mp[i][j] == 3) st = idx[i][j];
                if(mp[i][j] == 2) en = idx[i][j];
                if(mp[i][j] == 4) key = idx[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) edg[idx[i][j]].clear();
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j] == 1) continue;
                for(int k=0;k<4;k++){
                    int nx = i + X[k];
                    int ny = j + Y[k];
                    if(nx < 0 || ny < 0 || nx > n || ny > m || mp[nx][ny] == 1) continue;
                    edg[idx[i][j]].push_back(idx[nx][ny]);
                }
            }
        }
        if(f(st,key) == -1 || f(key,en) == -1){
            cout << "0\n";
        }else{
            cout << "1\n";
        }
    }
    return 0;
}