#include <bits/stdc++.h>

using namespace std;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	stack<pair<int,int>> s;
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		while(s.size()){
			if(s.top().second > x){
				cout << s.top().first << " ";
				break;
			}
			s.pop();
		}
		if(!s.size()) cout << "0 ";
		s.push({i,x});
	}
}