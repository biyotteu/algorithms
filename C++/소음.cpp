#include <bits/stdc++.h>

using namespace std;

int main(){
	string a,b;
	char c;
	cin >> a >> c >> b;
	if(c == '*'){
		cout << '1';
		for(int i=0;i<a.size()+b.size()-2;i++) cout << '0';
	}else{
		if(a.size()==b.size()){
			cout << '2';
			for(int i=0;i<a.size()-1;i++) cout << '0';
		}else{
			if(a.size() < b.size()) swap(a,b);
			cout << '1';
			for(int i=0;i<a.size()-1;i++){
				if(a.size()-i-1 == b.size()) cout << '1';
				else cout << '0';
			}
		}
	}
}