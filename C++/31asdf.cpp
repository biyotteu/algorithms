#include <iostream>

using namespace std;

int st[10005];
int top = -1;
void push(int x){
	st[++top] = x;
}
bool empty(){
	return top == -1;
}
int pop(){
	if(empty()) return -1;
	return st[top--];
}
int top_(){
	if(empty()) return -1;
	return st[top];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int q;
	cin >> q;
	while(q--){
		string str;
		cin >> str;
		if(str == "push"){
			int x;
			cin >> x;
			push(x);
		}else if(str == "pop"){
			cout << pop() << "\n";
		}else if(str == "size"){
			cout << top+1 << "\n";
		}else if(str == "empty"){
			cout << empty() << "\n";
		}else{
			cout << top_() << "\n";
		}
	}
}