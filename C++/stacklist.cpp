#include <bits/stdc++.h>

using namespace std;

struct node{
	int data;
	node *link;
};
node *top;
bool empty(){
	return top == NULL;
}
void push(int data){
	node *newnode = new node;
	newnode->data = data;
	newnode->link = top;
	top = newnode;
}
void pop(){
	node *tmp = top;
	top = top->link;
	delete tmp;
}
int top_(){
	return top->data;
}
int main(){
	push(1);
	push(2);
	push(3);
	cout << top_();
	pop();
	cout << top_();
}