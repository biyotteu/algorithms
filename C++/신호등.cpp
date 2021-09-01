#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N,M,S,D;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    cin >> N >> M >> S >> D;
    vector<vector<pair<ll,ll>>> edg(N+1);
    vector<ll> P(N+1);
    vector<vector<ll>> node(N+1);
    for(ll i=0;i<M;i++){
      ll x,y,z;
      cin >> x >> y >> z;
      node[x].push_back(y);
      node[y].push_back(x);
      edg[x].push_back({y,z});
      edg[y].push_back({x,z});
    }
    for(ll i=1;i<=N;i++){
      cin >> P[i];
      sort(node[i].begin(),node[i].end());
    }
    priority_queue<pair<ll,ll>> q;
    q.push({0,S});
    vector<ll> dist(N+1,-1);
    dist[S] = 0;
    while(!q.empty()){
      pair<ll,ll> cur = q.top();q.pop();
      cur.first = -cur.first;
      if(cur.first > dist[cur.second]) continue;
      for(auto i:edg[cur.second]){
        
          ll ds = cur.first + i.second;
          ll size = (ll)(node[i.first].size() * P[i.first]);
          ll k = ds - ds%size;
          ll cnt = lower_bound(node[i.first].begin(),node[i.first].end(),cur.second) - node[i.first].begin() + 1;
          ll nx;
          
          if(i.first == D || (k + (cnt-1)*P[i.first] <= ds && ds < k + cnt*P[i.first])){
            nx = ds;
          }else{
            nx = k + (cnt-1)*P[i.first] + size;
          }
          if(dist[i.first] == -1 || dist[i.first] > nx){
            dist[i.first] = nx;
            q.push({-nx,i.first});
          }
        
      }
    }
    cout << dist[D] << "\n";
  }
}