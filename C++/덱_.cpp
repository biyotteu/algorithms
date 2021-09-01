#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int q;
	cin >> q;
	deque<int> dq;
	while(q--){
		string str;
		cin >> str;
		if(str.compare("push_front") == 0){
			int x;
			cin >> x;
			dq.push_front(x);
		}else if(str.compare("push_back") == 0){
			int x;
			cin >> x;
			dq.push_back(x);
		}else if(str.compare("pop_front") == 0){
			if(dq.empty()){
				cout << -1 << "\n";
			}else{
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}else if(str.compare("pop_back") == 0){
			if(dq.empty()){
				cout << -1 << "\n";
			}else{
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}else if(str.compare("size") == 0){
			cout << dq.size() << "\n";
		}else if(str.compare("empty") == 0){
			cout << (dq.empty() ? 1:0) << "\n"; 
		}else if(str.compare("front") == 0){
			if(dq.empty()) cout << -1 << "\n";
			else cout << dq.front() << "\n";
		}else{
			if(dq.empty()) cout << -1 << "\n";
			else cout << dq.back() << "\n";
		}
	}
}