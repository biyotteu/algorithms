#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	set<int> s;
	while(n--){
		string x;
		int y;
		cin >> x;
		if(!x.compare("add")){
			cin >> y;
			s.insert(y);
		}else if(!x.compare("remove")){
			cin >> y;
			if(s.find(y) == s.end()) continue;
			s.erase(y);
		}else if(!x.compare("check")){
			cin >> y;
			if(s.find(y) != s.end()) cout << "1\n";
			else cout << "0\n";
		}else if(!x.compare("toggle")){
			cin >> y;
			if(s.find(y) != s.end()) s.erase(y);
			else s.insert(y);
		}else if(!x.compare("all")){
			for(int i=1;i<21;i++) s.insert(i);
		}else{
			s.clear();
		}
	}
	
}