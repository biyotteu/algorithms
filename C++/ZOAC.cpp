#include <bits/stdc++.h>

using namespace std;

int main(){
	string ss;
	cin >> ss;
	int m = 200,idx;
	for(int i=0;i<ss.size();i++){
		if(m > ss[i]){
			m = ss[i];
			idx = i;
		}
	}
	string a,aa,b,bb;
	a = aa = ss.substr(0,idx);
	b = bb = ss.substr(idx+1,ss.size()-idx-1);
	sort(aa.begin(),aa.end());
	sort(bb.begin(),bb.end());
	cout << ss[idx] << "\n";
	for(auto i:bb){
		cout << ss[idx];
		for(auto j:b) if(j<=i) cout << j;
		cout << "\n";
	}
	for(auto i:aa){
		for(auto j:a) if(j<=i) cout << j;
		cout << ss[idx];
		cout << b;
		cout << "\n";
	}

}