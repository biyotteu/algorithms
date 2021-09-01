#include <bits/stdc++.h>
 
using namespace std;
 
long long n,m,ch[55][55];
long long cost(int x,int y,int x1,int y1){
    return ch[x1][y1] - ch[x-1][y1] - ch[x1][y-1] + ch[x-1][y-1];
}
long long f(int x,int y,int x1,int y1){
    if(x == x1 && y == y1) return 0;
    long long ret = 98765432198LL;
    for(int i=x;i<x1;i++)
        ret = min(ret,f(x,y,i,y1) + cost(x,y,i,y1) + f(i+1,y,x1,y1) + cost(i+1,y,x1,y1));
    for(int i=y;i<y1;i++)
        ret = min(ret,f(x,y,x1,i) + cost(x,y,x1,i) + f(x,i+1,x1,y1) + cost(x,i+1,x1,y1));
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> ch[i][j];
            ch[i][j] += (ch[i-1][j]+ch[i][j-1]-ch[i-1][j-1]);
        }
    }
    cout << f(1,1,n,m);
}