#include <bits/stdc++.h>
#include <fstream>

using namespace std;

struct info{
	int x,y,z;
	bool operator<(info A)const{
		if(A.x == x) return z < A.z;
		return x < A.x;
	}
};
struct cmp{
    bool operator()(info t, info u){
        return t.z > u.z;
    }
};
int n,res,last;
vector<info> cow;
priority_queue<info,vector<info>,cmp> pq;
int main(){
	ifstream ifn("convention2.in");
	ofstream ofn("convention2.out");
	ifn >> n;
	for(int i=0;i<n;i++){
		int x,y;
		ifn >> x >> y;
		cow.push_back({x,y,i});
	}
	sort(cow.begin(),cow.end());

	last = cow[0].x + cow[0].y;
 	for(int i=1;i<n;i++){
 		if(last >= cow[i].x){
 			pq.push(cow[i]);
 		}else{
 			while(!pq.empty()){ 
 				info cur = pq.top();
 				res = max(res,last-cur.x);
 				last = last+cur.y;
 				pq.pop();
 				if(last >= cow[i].x) break;
 			}
 			if(pq.empty()) last = cow[i].x + cow[i].y;
 			else pq.push(cow[i]);
 		}
	}
	ofn << res;
	ifn.close();
	ofn.close();
	return 0;
}