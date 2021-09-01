#include <bits/stdc++.h>

using namespace std;

deque<int> q;
int main(){
	int t;
	cin >> t;
	while(t--){
		string str;
		cin >> str;
		if(str == "push"){
			int x;
			cin >> x;
			q.push_back(x);
		}
		else if(str == "pop"){
			if(q.size() > 0){
				cout << q.front() << "\n";
				q.pop_front();
			}else	cout << "-1\n";
		}
		else if(str == "size") cout << q.size() << "\n";
		else if(str == "empty") cout << q.empty() << "\n";
		else if(str == "front")
			if(q.size() > 0) cout << q.front() << "\n";
			else cout << "-1\n";
		else
			if(q.size() > 0) cout << q.back() <<"\n";
			else cout << "-1\n";
	}
}