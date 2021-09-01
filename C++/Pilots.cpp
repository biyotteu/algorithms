#include <bits/stdc++.h>
#define value first
#define idx second

using namespace std;
using pp = pair<int,int>;

int n,t,res,cnt,last;
deque<pp> minQ,maxQ;
int main(){
	scanf("%d %d",&t,&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		while(minQ.size() && minQ.back().value >= x) minQ.pop_back();
		while(maxQ.size() && maxQ.back().value <= x) maxQ.pop_back();
		minQ.push_back({x,i});
		maxQ.push_back({x,i});
		while(maxQ.front().value - minQ.front().value > t){
			if(maxQ.front().idx > minQ.front().idx){
				last = minQ.front().idx;
				minQ.pop_front();
			}
			else{ 
				last = maxQ.front().idx;
				maxQ.pop_front();
			}
		}
		res = max(res,i - last);
	}
	printf("%d",res);
}