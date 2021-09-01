#include <bits/stdc++.h>

struct node{
	node *left,*right;
	char data;
};
void init(node *v,char cdata){
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = cdata;
	newNode->left = v;
	newNode->right = NULL;
	v->right = newNode;
	return;
}
void push(node *v,char cdata){
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = cdata;
	newNode->right = v;
	newNode->left = v->left;
	if(v->left!=NULL) v->left->right = newNode;
	v->left = newNode;
}
void dis(node *tmp){
	while(tmp->left!=NULL) tmp = tmp->left;
	while(tmp!=NULL){
		printf("%c",tmp->data);
		tmp = tmp->right;
	}
	printf("\n");
	return;
}
int main(){
	char str[100005];
	scanf("%s",str);
	int n = strlen(str);
	struct node *head = (node*)malloc(sizeof(node));
	for(int i=0;i<n;i++){
		init(head,str[i]);
		head = head->right;
		if(i==0) head->left = NULL;
	}
	init(head,'|');
	head = head->right;
	int m;
	scanf("%d",&m);
	while(m--){
		char c;
		scanf(" %c",&c);
		if(c == '|'){
			char  x;
			scanf(" %c",&x);
			push(head,x);
		}
		if(c == 'L'){
			if(head->left == NULL) continue;
			head->left->right = head->right;
			if(head->right != NULL) head->right->left = head->left;
			head->left = head->left->left;
			head->right = head->left->right;
			if(head->left!=NULL) head->left->right = head;
			if(head->right!=NULL) head->right->left = head;
		}
		if(c == 'R'){
			if(head->right == NULL) continue;
			if(head->left != NULL) head->left->right = head->right;
			head->right->left = head->left;
			head->left = head->right;
			head->right = head->left->right;
			if(head->right!=NULL) head->right->left = head;
			if(head->left!=NULL) head->left->right = head;
		}
		if(c == 'D'){
			if(head->right == NULL) continue;
			if(head->right->right!=NULL) head->right->right->left = head;
			head->right = head->right->right;
		}
		if(c == 'P') dis(head);
	}
}