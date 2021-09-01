#include <bits/stdc++.h>

using namespace std;

struct node{
	struct node *left, *right;
	char data;
};
char str[100005];
void create(node *L, char vdata){
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = vdata;
	newNode->left = L;
	newNode->right = NULL;
	L->right = newNode;
	return;
}
void push(node *v,char vdata){
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = vdata;
	newNode->right = v;
	newNode->left = v->left;
	if(v->left !=NULL) v->left->right = newNode;
	v->left = newNode;
}
int main(){
	struct node *cur = (node*)malloc(sizeof(struct node));
	cur->left = NULL;
	scanf("%s",str);
	int n = strlen(str);
	for(int i=0;i<n;i++){
		create(cur,str[i]);
		cur = cur->right;
		if(i == 0) cur->left = NULL;
	}
	create(cur,NULL);
	cur = cur->right;
	int m;
	scanf("%d",&m);
	while(m--){
		char c;
		scanf(" %c",&c);
		if(c == 'P'){
			char x;
			scanf(" %c",&x);
			push(cur,x);
		}
		if(c == 'L') if(cur->left != NULL) cur = cur->left;
		if(c == 'D') if(cur->right != NULL) cur = cur->right;
		if(c == 'B'){
			if(cur->left == NULL) continue;
			cur = cur->left;
			if(cur->left != NULL) cur->left->right = cur->right;
			if(cur->right != NULL) cur->right->left = cur->left;
			cur = cur->right;
		}
	}
	while(cur->left != NULL) cur = cur->left;
	while(cur->right!=NULL){
		printf("%c", cur->data);
		cur = cur->right;
	}
}