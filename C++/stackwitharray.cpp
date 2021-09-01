#include <iostream>

using namespace std;

struct node{
	int data;
	node *link;
};

int size = 0;
node *top;

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
bool empty(){
	return top == NULL;
}
int main(){
	push(3);
	push(2);
	push(1);
	cout << top_() << "\n";
	pop();
	pop();
	cout << top_() << "\n";
	cout << empty() << "\n";
	pop();
	cout << empty() << "\n";
}