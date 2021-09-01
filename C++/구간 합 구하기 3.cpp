#include <bits/stdc++.h>

using namespace std;

int n,m,_size;
vector<vector<long long>> seg;
void update1(int node,int start,int end,int row,int idx,int value){
    if(start > idx || end < idx) return;
    if(start == end){
        seg[row][node] = value;
        while(row/=2) seg[row][node] = seg[row*2][node] + seg[row*2+1][node];
    } 
    else{
        update1(node*2,start,(start+end)/2,row,idx,value);
        update1(node*2+1,(start+end)/2+1,end,row,idx,value);
        seg[row][node] = seg[row][node*2] + seg[row][node*2+1];
        while(row/=2) seg[row][node] = seg[row*2][node] + seg[row*2+1][node];
    }
}
void update2(int node,int start,int end,int row,int idx,int value){
    if(start > row || end < row) return;
    if(start == end) update1(1,1,n,node,idx,value);
    else{
        update2(node*2,start,(start+end)/2,row,idx,value);
        update2(node*2+1,(start+end)/2+1,end,row,idx,value);
    }
}
long long sum1(int node,int start,int end,int x1,int y1,int x2,int y2,int row){
    if(start > y2 || end < y1) return 0;
    if(start >= y1 && y2 >= end) return seg[row][node];
    return sum1(node*2,start,(start+end)/2,x1,y1,x2,y2,row)+sum1(node*2+1,(start+end)/2+1,end,x1,y1,x2,y2,row);
}
long long sum2(int node,int start,int end,int x1,int y1,int x2,int y2){
    if(start > x2 || end < x1) return 0;
    if(x1 <= start && end <= x2){
        //cout << sum1(1,1,n,x1,y1,x2,y2,node) << ' ' << start << end << node<<"@@@@\n";
        return sum1(1,1,n,x1,y1,x2,y2,node);
    } 
    return sum2(node*2,start,(start+end)/2,x1,y1,x2,y2) + sum2(node*2+1,(start+end)/2+1,end,x1,y1,x2,y2);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    _size = 1<<((int)ceil(log2(n)) + 1);
    seg.resize(_size);
    for(int i=0;i<_size;i++) seg[i].resize(_size);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int cur;
            cin >> cur;
            update2(1,1,n,i,j,cur);
        }
    }
    while(m--){
        int w;
        cin >> w;
        if(w){
            pair<int,int> x,y;
            cin >> x.first >> x.second >> y.first >> y.second;
            if(x.first > y.first) swap(x,y);
            cout << sum2(1,1,n,x.first,x.second,y.first,y.second) << "\n";
        }else{
            int x,y,c;
            cin >> x >> y >> c;
            update2(1,1,n,x,y,c);
        }
    }
    //for(auto i:seg[2]) cout << i << "###";
}
