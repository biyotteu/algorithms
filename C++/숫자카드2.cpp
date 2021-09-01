#include <bits/stdc++.h>

using namespace std;

int n,k;
int pp[4000005],mm[4000005];
vector<int> ma,pl;
set<int> mmm,ppp;
long long res = 0;
int main(){
	cin >> n >> k;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		if(x<0) ma.push_back(-x);
		else pl.push_back(x);
	}
	for(int i=0;i<pl.size();i++){
		vector<pair<int,int>> tmp;
		for(auto j:ppp){
			tmp.push_back({j+pl[i],pp[j]});
		}
		for(auto j:tmp){
			pp[j.first] += j.second;
			ppp.insert(j.first);
		}
		pp[pl[i]]++;
		ppp.insert(pl[i]);
	}
	for(int i=0;i<ma.size();i++){
		vector<pair<int,int>> tmp;
		for(auto j:mmm){
			tmp.push_back({j+ma[i],mm[j]});
		}
		for(auto j:tmp){
			mm[j.first] += j.second;
			mmm.insert(j.first);
		}
		mm[ma[i]]++;
		mmm.insert(ma[i]);
	}
	
	if(k>=0){
		res += pp[k];
		//cout << res;
		for(int i=k+1;i<=4000000;i++)
			res += pp[i]*mm[i-k];
	}else{
		k*=-1;
		res += ma[k];
		for(int i=k+1;i<=4000000;i++)
			res += mm[i]*pp[i-k];
	}
	cout << res;
}