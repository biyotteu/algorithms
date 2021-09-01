#include <bits/stdc++.h>
#include <fstream>

using namespace std;

struct info{
	int x,y,z;
	bool operator<(info A)const{
		return x < A.x;
	}
};
struct cmp{
    bool operator()(info t, info u){
        return t.y > u.y;
    }
};
int n,bck,res;
vector<info> cow;
priority_queue<info,vector<info>,cmp> pq;
int main(){
	ifstream ifn("blist.in");
	ofstream ofn("blist.out");
	ifn >> n;
	for(int i=0;i<n;i++){
		int x,y,z;
		ifn >> x >> y >> z;
		cow.push_back({x,y,z});
	}
	sort(cow.begin(),cow.end());
	bck += cow[0].z;
	pq.push(cow[0]);
	int size = cow.size();
	for(int i=1;i<size;i++){
		while(!pq.empty()){
			info cur = pq.top();
			if(cur.y < cow[i].x){
				res += cur.z;
				bck -= cur.z;
				pq.pop();
			}
			else break;
		}
		bck += cow[i].z;
		res = max(0,res-cow[i].z);
		pq.push(cow[i]);
	}
	res += bck;
	ofn << res;
}