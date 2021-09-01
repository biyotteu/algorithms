#include <bits/stdc++.h>

using namespace std;

int n;
long long int node[200005][2];
vector<int> tree[200005];
void f(int v,long long int b,int l){
	if(tree[v].empty()){
		node[v][l] = b;
		return;
	}
	else if(tree[v].size() == 1){
		f(tree[v][0],b,l);
		return;
	}
	else{
		f(tree[v][0],b/2+b%2,l);
		f(tree[v][1],b/2,l);
		return;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin >> x >> y;
		if(x!=-1)	tree[i].push_back(x);
		if(y!=-1) 	tree[i].push_back(y);
	}
	long long int k;
	cin >> k;
	f(1,k,0); 
	f(1,k-1,1);
	for(int i=1;i<=n;i++)
		if(node[i][0] != node[i][1]){
			cout << i;
			break;
		}
}