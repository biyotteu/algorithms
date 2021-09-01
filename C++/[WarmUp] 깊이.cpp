#include <bits/stdc++.h>

using namespace std;

int n,sq[200005],cnt = 1,res;
stack<int> st;
string str;
int main(){
	 cin >> n;
	 cin >> str;
	 st.push(0);
	 for(int i=1;i<n;i++){
	 	if(str[i]==')'){
	 		res = max(cnt,res);
	 		sq[st.top()] = cnt;
	 		sq[i] = cnt;
	 		st.pop();
	 		cnt--;
	 	}else{
	 		cnt++; 
	 		st.push(i);
	 	}
	 }
	 cout << (res+1)/2 << '\n';
	 for(int i=0;i<n;i++) cout << sq[i]%2;
}