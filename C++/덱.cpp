#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	deque<int> q;
	cin >> n;
	while(n--){
		string x;
		int y;
		cin >> x;
		if(!x.compare("push_front")){
			cin >> y;
			q.push_front(y);
		} 
		if(!x.compare("push_back")) {
			cin >> y;
			q.push_back(y);
		}
		if(!x.compare("pop_front")){
			if(q.empty()) cout << "-1\n";
			else{
				cout << q.front() << "\n";
				q.pop_front();
			}
		}
		if(!x.compare("pop_back")){
			if(q.empty()) cout << "-1\n";
			else{
				cout << q.back() << "\n";
				q.pop_back();
			}
		}
		if(!x.compare("size")) cout << q.size() << "\n";
		if(!x.compare("empty")) cout << q.empty() << "\n";
		if(!x.compare("front")){
			if(q.empty()) cout << "-1\n";
			else cout << q.front() << "\n";
		} 
		if(!x.compare("back")){ 
			if(q.empty()) cout << "-1\n";
			else cout << q.back() << "\n";
		}

	}
}