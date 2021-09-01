#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<pair<int,pair<int,int>>> X;
int main(){
	cin >> m >> n;
	if(m==3){
		X.resize(n);
		for(int i=0;i<n;i++) cin >> X[i].first;
		for(int i=0;i<n;i++) cin >> X[i].second.first;
		for(int i=0;i<n;i++) cin >> X[i].second.second;
		sort(X.begin(),X.end());
		vector<pair<int,int>> num;
		vector<int> num1;
		for(auto i:X){
			pair<int,int> cur = i.second;
			if(num.empty()) num.push_back(cur);
			else if(num.back().first < cur.first && num.back().second < cur.second) num.push_back(cur);
			else{
				auto idx = lower_bound(num.begin(),num.end(),cur);
				*idx = cur;
			}
		}
		for(auto i:num) cout << i.first << ' ';
		cout << endl;
			for(auto i:num) cout << i.second << ' ';
		for(int i=0;i<n;i++) cout << X[i].first << ' ';
		cout << "\n";
		for(int i=0;i<n;i++) cout << X[i].second.first << ' ';
		cout << "\n";
		for(int i=0;i<n;i++) cout << X[i].second.second << ' ';
		cout << "\n";
	}else{
		vector<pair<int,int>> pp;
		pp.resize(n);
		for(int i=0;i<n;i++) cin >> pp[i].first;
		for(int i=0;i<n;i++) cin >> pp[i].second;
		sort(pp.begin(),pp.end());
		vector<int> num;
		for(auto i:pp){
			if(num.empty()) num.push_back(i.second);
			else if(num.back() < i.second) num.push_back(i.second);
			else{
				auto idx = lower_bound(num.begin(),num.end(),i.second);
				*idx = i.second;
			}
		}
		cout << num.size();
	}
}