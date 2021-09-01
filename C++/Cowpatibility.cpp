#include <bits/stdc++.h>

using namespace std;

struct info{
	int a,b,c,d,e;
	bool operator==(info A)const{
		if(a == A.a && b == A.b && c == A.c && d == A.d && e == A.e) return 1;
		return 0;
	}
	bool operator<(info A)const{
		if(a == A.a){
			if(b == A.b){
				if(c == A.c){
					if(d == A.d){
						return e < A.e;
					}
					return d < A.d;
				}
				return c < A.c;
			}
			return b < A.b;	
		}
		return a < A.a;
	}
	void print(){
		printf("%d %d %d %d %d\n", a, b, c, d, e);
	}
};
int n,num1[1000005];
vector<int> numm[6];
vector<info> num[6];
vector<vector<int>> cow;
void f(int v,int cnt,int limit,int idx,vector<int> list){
	if(v>5) return;
	if(cnt == limit){
		info cur;
		cur.a = list[0];
		cur.b = list[1];
		cur.c = list[2];
		cur.d = list[3];
		cur.e = list[4];
		num[limit].push_back(cur);
		return;
	}
	f(v+1,cnt,limit,idx,list);
	list[cnt] = cow[idx][v];
	f(v+1,cnt+1,limit,idx,list);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++){
		vector<int> cur;
		for(int j=0;j<5;j++){
			int x;
			cin >> x;
			cur.push_back(x);
			num1[x]++;
		}
		sort(cur.begin(),cur.end());
		cow.push_back(cur);
	}
	long long res = 0;
	for(int i=1;i<=1000000;i++)	res += num1[i]*(num1[i]-1)/2;
	for(int i=2;i<=5;i++){
		for(int j=0;j<n;j++){
			vector<int> cmp(5,0);
			f(0,0,i,j,cmp);
		}
		sort(num[i].begin(),num[i].end());
		int cnt = 1;
		for(int j=1;j<num[i].size();j++){
			if(num[i][j] == num[i][j-1]){
				cnt++;
			}else{
				if(cnt >= 2){
					numm[i].push_back(cnt);
					cnt = 1;
				}
			}
		}
		if(cnt >= 2){
			numm[i].push_back(cnt);
		}
	}
	for(int i=2;i<=5;i++){
		cout << i <<"@@@@@" <<endl;
		for(auto o:numm[i]){
			cout << i << ' ';
			if(i%2) res += o*(o-1)/2;
			else res -= o*(o-1)/2;
		}
		cout << endl;
	}
	cout << "@@@"<<res;
}