#include <bits/stdc++.h>

using namespace std;

struct Node{
public:
	int left,right;
	Node(){left=right=0;}
};

Node tree[27];

void f1(int v){
	cout << (char)(v+64);
	if(tree[v].left) f1(tree[v].left);
	if(tree[v].right) f1(tree[v].right);
}
void f2(int v){
	if(tree[v].left) f2(tree[v].left);
	cout << (char)(v+64);
	if(tree[v].right) f2(tree[v].right);
}
void f3(int v){
	if(tree[v].left) f3(tree[v].left);
	if(tree[v].right) f3(tree[v].right);
	cout << (char)(v+64);
}
int main(){
	int n;
	cin >> n;
	while(n--){
		char x,y,z;
		cin >> x >> y >> z;
		if(y != '.') tree[x-64].left = y - 64;
		if(z != '.') tree[x-64].right = z - 64;
	}
	f1(1);
	cout << "\n";
	f2(1);
	cout << "\n";
	f3(1);
}