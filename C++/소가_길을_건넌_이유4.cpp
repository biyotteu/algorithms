#include <bits/stdc++.h>
  
using namespace std;
  
int c,n,res;
vector<pair<int,int>> A;
vector<int> T;
bool cmp(pair<int,int> A,pair<int,int> B){
    if(A.second == B.second) return A.first<B.first;
    return A.second < B.second;
}
int main(){
    scanf("%d %d",&c,&n);
    for(int i=0;i<c;i++){
        int x;
        scanf("%d",&x);
        T.push_back(x);
    }
    T.push_back((1<<29));
    sort(T.begin(),T.end());
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        A.push_back({x,y});
    }
    sort(A.begin(),A.end(),cmp);
    for(int i=0;i<n;i++){
        vector<int>::iterator k = lower_bound(T.begin(),T.end(),A[i].first);
        if(*k<=A[i].second){
            res++;
            T.erase(k);
        }
    }
    printf("%d",res);
}