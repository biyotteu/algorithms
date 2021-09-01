#include <bits/stdc++.h>

using namespace std;

vector<int> a;
int T,t,n;
int main(){
	cin >> T;
	for(int p=1;p<=T;p++){
		string str;
		cin >> n >> t;
		a.clear();
		a.resize(n,-1);
		cin >> str;
		int last = 0;
		for(int i=0;i<n;i++){
			if(str[i] == '1') continue;
			if(i-t >= 0) a[i-t] = 0;
			if(i+t < n) a[i+t] = 0;
		}
		for(int i=0;i<n;i++){
			if(str[i] == '0') continue;
			if(i-t >= 0 && a[i-t] == 1) continue;
			if(i+t < n && a[i+t] == -1){
				if(i-t >= 0) a[i-t] = 0;
				a[i+t] = 1;
			}else{
				a[i-t] = 1;
			}
		}

		cout << "Case #" << p << "\n";
		for(int i=0;i<n;i++){
			if(a[i] == -1) cout << 0;
			else cout << a[i];
		}
		cout << "\n";
	}
}