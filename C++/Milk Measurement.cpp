//백준 15461;
//그리디 문제
//cow = 소 정보, onboard[i] = i gallon의 소의 수
//좌표 압축을 사용하여 그리디를 통해 풀 수 있지만
//map을 사용하면 쉽고 간단하게 풀 수 있다

#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y,z;
};
bool cmp(const info &A, const info &B){
	return A.y < B.y;
}
bool cmp1(const info &A, const info &B){
	return A.x < B.x;
}
vector<info> cow;
vector<int> cost;
int n,g,res;
int main(){
	scanf("%d %d",&n,&g);
	cost.resize(n+1);
	for(int i=0;i<n;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		cow.push_back({a,b,c});
	}	
	sort(cow.begin(),cow.end(),cmp);
	int cnt = 1,idx = 1,be = cow[0].y;
	cow[0].y = cnt;
 	while(idx < cow.size()){
 		if(cow[idx].y == be) cow[idx++].y = cnt;
 		else{
 			be = cow[idx].y;
 			cow[idx++].y = ++cnt;
 		}
	}
	sort(cow.begin(),cow.end(),cmp1);
	map<int,int,greater<int>> onboard;
	onboard[0] = n+1;
	for(int i=0;i<n;i++){
		bool beon = (onboard.begin()->first == cost[cow[i].y]);
		int becnt = --onboard[cost[cow[i].y]];
		if(!becnt)
			onboard.erase(cost[cow[i].y]);
		cost[cow[i].y] += cow[i].z;
		int curcnt = ++onboard[cost[cow[i].y]];
		bool curon = cost[cow[i].y] == onboard.begin()->first;
		if(beon){
			if(!curon || becnt || curcnt != 1) res++;
		}else if(curon) res++;
	}
	printf("%d",res);
}