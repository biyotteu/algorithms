#include <bits/stdc++.h>

using namespace std;

struct info{
	int cost;
	int ap[26];
};
string str;
int n,res = (1<<29),k[26];
vector<info> book;
void f(int v,int sum,int al[]){
	if(sum > res) return;
	if(v == n){
		int cmp = 0;
		for(int i=0;i<26;i++) cmp += al[i];
		if(!cmp) res = min(res,sum);
		return;
	}
	f(v+1,sum,al);
	for(int i=0;i<26;i++){

		if(al[i] <= book[v].ap[i]) al[i] = 0;
		else al[i] -= book[v].ap[i];
	}
	f(v+1,sum+book[v].cost,al);
}
int main(){
	cin >> str;
	cin >> n;
	book.resize(n);
	for(int i=0;i<n;i++){
		cin >> book[i].cost;
		string st;
		cin >> st;
		for(auto ii:st)	book[i].ap[ii-65]++;
		for(int p=0;p<26;p++) cout << (char)(p+65) << ' ';
			cout << endl;
		for(int p=0;p<26;p++) cout << book[i].ap[p] << ' ';
			cout << endl << endl;
	}
	for(auto i:str) k[i-65]++;
	f(0,0,k);
	if(res == (1<<29)){
		cout << -1;
		return 0;
	}
	cout << res;
}