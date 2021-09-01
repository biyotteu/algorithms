#include <bits/stdc++.h>
#include <fstream>

using namespace std;

set<int> S;
void f(int cnt,int suma,int sumb,vector<int> a,vector<int> b){
	if(cnt >= 5){
		S.insert(suma);
		return;
	}
	if(cnt%2){
		for(int k=0;k<a.size();k++){
			int &i = a[k];
			if(i == -1) continue;
			int t = i;
			i = -1;
			b.push_back(t);
			f(cnt+1,suma-t,sumb+t,a,b);
			b.pop_back();
			i = t;
		}
	}
	if(cnt%2 == 0){
		for(int k=0;k<b.size();k++){
			int &i = b[k];
			if(i == -1) continue;
			int t = i;
			i = -1;
			a.push_back(t);
			f(cnt+1,suma+t,sumb-t,a,b);
			a.pop_back();
			i = t;
		}
	}
}
int main(){
	ifstream ifn("backforth.in");
	ofstream ofn("backforth.out");
	vector<int> A,B;
	for(int i=0;i<10;i++){
		int x;
		ifn >> x;
		A.push_back(x);
	}
	for(int i=0;i<10;i++){
		int x;
		ifn >> x;
		B.push_back(x);
	}
	f(1,1000,1000,A,B);
	ofn << S.size();
	ifn.close();
	ofn.close();
	return 0;
}