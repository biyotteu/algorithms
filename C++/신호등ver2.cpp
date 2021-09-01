#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    int N,M,S,D;    
    cin >> N >> M >> S >> D;

    vector<vector<pair<int,ll>>> edg(N+1);
    vector<ll> P(N+1);

    for(int i=0;i<M;i++){
      int x,y;
      ll z;
      cin >> x >> y >> z;
      edg[x].push_back({y,z});
      edg[y].push_back({x,z});
    }

    for(ll i=1;i<=N;i++){
      cin >> P[i];
      sort(edg[i].begin(),edg[i].end());
    }

    priority_queue<pair<ll,int>> q;
    q.push({0,S});
    vector<ll> dist(N+1,-1);
    dist[S] = 0;

    while(!q.empty()){
      pair<ll,int> cur = q.top();q.pop();
      cur.first = -cur.first;
      if(cur.first > dist[cur.second]) continue;
      for(auto i:edg[cur.second]){
        
          ll ds = cur.first + i.second;
          ll size = (ll)(edg[i.first].size() * P[i.first]);
          ll k = ds - ds%size; 
          ll cnt = lower_bound(edg[i.first].begin(),edg[i.first].end(),make_pair(cur.second,i.second)) - edg[i.first].begin();
          ll nx;
          
          if(i.first == D || (k + cnt*P[i.first] <= ds && ds < k + (cnt+1)*P[i.first])){
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