#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> num,mnum;
deque<int> mres,res;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		if(x<0) mnum.push_back(x);
		else num.push_back(x);
	}
	sort(mnum.begin(),mnum.end());		
	sort(num.rbegin(),num.rend());
	int c = 0;
	for(auto i:num){
		if(c%2) res.push_back(i);
		else res.push_front(i);
		c++;
	}
	for(auto i:mnum){
		if(c%2) mres.push_back(i);
		else mres.push_front(i);
		c++;
	}
	if(res.empty()){
		for(auto i:mres) cout << i << ' ';
	}else if(mres.empty()){
		for(auto i:res) cout << i << ' ';
	}else{
		if(res.front() >= res.back() && mres.front() >= mres.back()){
			for(auto i:res) cout<< i << ' ';
			for(auto i:mres) cout<< i << ' ';
		}else if(res.front() >= res.back() && mres.front() <= mres.back()){
			for(auto i:res) cout<< i << ' ';
			while(!mres.empty()){
				cout << mres.back() << ' ';
				mres.pop_back();
			}
		}else if(res.front() <= res.back() && mres.front() >= mres.back()){
			while(!mres.empty()){
				cout << mres.back() << ' ';
				mres.pop_back();
			}
			for(auto i:res) cout<< i << ' ';
		}else if(res.front() <= res.back() && mres.front() <= mres.back()){
			for(auto i:mres) cout<< i << ' ';
			for(auto i:res) cout<< i << ' ';
		}
	}
}
