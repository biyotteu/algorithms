#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str,t;
    cin >> str;
    cin >> t;
    vector<char> Q;
    for(int i=0;i<str.size();i++){
    	Q.push_back(str[i]);
    	int idx = Q.size()-1, cmp = 0;
    	if(idx < t.size()-1) continue;
    	for(int j=t.size()-1;j>=0;j--){
    		if(idx<0 || Q[idx] != t[j]){
    			cmp = 1;
    			break;
    		}
    		idx--;
    	}
    	if(!cmp){
    		for(int j=t.size()-1;j>=0;j--) if(!Q.empty()) Q.pop_back();
    	}
    }
    for(auto i:Q) cout << i;
}