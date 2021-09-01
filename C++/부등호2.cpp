#include <bits/stdc++.h>

using namespace std;

int n,res[15],lvl[15],cnt=9;
vector<int> tree[15];
void f(int v){
	res[v] = cnt--;
	for(auto i:tree[v])	f(i);
}
void g(int v){
	for(auto i:tree[v]) g(i);
	res[v] = cnt++;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char c;
		scanf(" %c",&c);
		if(c == '<'){
			tree[i+1].push_back(i);
			lvl[i]++;
		}
		else{
			tree[i].push_back(i+1);
			lvl[i+1]++;
		}
	}
	for(int i=1;i<=n+1;i++)
		if(!lvl[i]) f(i);
	for(int i=1;i<=n+1;i++)
		printf("%d",res[i]);
	puts("");
	cnt = 0;
	for(int i=1;i<=n+1;i++)
		if(!lvl[i]) g(i);
	for(int i=1;i<=n+1;i++)
		printf("%d",res[i]);

}