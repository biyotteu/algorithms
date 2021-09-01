#include <bits/stdc++.h>
#define INF 98765432198LL
using namespace std;

struct info{
	int num[3];
};
bool cmp0(const info &A,const info &B){
	return A.num[0] < B.num[0];
}
int m,n,res,tmp[3][200005];
info cell[200005];
//vector<vector<int>> tmp;
vector<set<pair<int,int>>> S;
bool diff(int k,pair<int,int> A){
	if(S[k].empty()) return false;
	auto p = lower_bound(S[k].begin(),S[k].end(),A);
	if(p == S[k].begin()) return false;
	p--;
	if((*p).second < A.second) return true;
	else return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int x;
			cin >> x;
			tmp[i][j] = x;
		}
	}
	for(int j=0;j<n;j++)
		for(int i=0;i<m;i++)
			cell[j].num[i] = tmp[i][j];
	sort(cell,cell+n,cmp0);
	if(m == 2){
		vector<int> li;
		li.push_back(-INF);
		for(int i=0;i<n;i++){
			if(li.back() < cell[i].num[1])
				li.push_back(cell[i].num[1]);
			else{
				auto cur = lower_bound(li.begin(),li.end(),cell[i].num[1]);
				*cur = cell[i].num[1];
			}
		}
		cout << li.size()-1;	
	}
	if(m == 3){
		S.resize(n+1);
		S[0].insert({0,0});
		for(int i=0;i<n;i++){
			int l = 0,r = n;
			while(l<r){
				int mid = (l+r)/2;
				if(diff(mid,make_pair(cell[i].num[1],cell[i].num[2]))) l = mid;
				else r = mid - 1;
				if(l+1==r){
					//printf("l:%d\n", l);
					if(diff(l+1,make_pair(cell[i].num[1],cell[i].num[2]))) l++;
					break;
				}
			}
			l++;
			res = max(res,l);
			//for(auto it = S[2].begin(); it != S[2].end(); it++) printf("%d %d\n", it->first, it->second);
			//puts("@@");
			if(!S[l].empty()){
				auto o1 =lower_bound(S[l].begin(),S[l].end(),make_pair(cell[i].num[1],cell[i].num[2]));
				auto o2 = o1;
				for(auto j = o1; j != S[l].end(); j++){
					if((*j).second > cell[i].num[2]){
						o2++;
					}
					else break;
				}
				S[l].erase(o1, o2);
			}
			S[l].insert({cell[i].num[1],cell[i].num[2]});
		}
		cout << res;
	}
}
cin.