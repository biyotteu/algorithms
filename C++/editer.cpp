#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct Node{
    char data;
    Node *front, *back;
};
struct List{
    Node *head, *tail;
};
 
List *list;
 
Node *new_node(char data){
    Node *node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->front=node->back=NULL;
    return node;
}
Node * insert(Node *cur, char data){
    Node *node=new_node(data);
    if(list->head==NULL&&list->tail==NULL){
        list->head=node;
        list->tail=node;
    }
    else{
        list->tail->back = node;
        node->front = list->tail;
        list->tail = node;
    }
    return node;
}
List *Delete(Node *cur){
    if(cur->front == list->head){ 
        list->head = list->head->back;
        cur->back = cur->front;
        cur->front = NULL;
    }
    else if(cur->front == list->tail){
        list->tail = list->tail->front;
        cur->front = list->tail;
    }else{
        cur->front->front->back = cur->back;
        cur->back->front = cur->front->front;
        cur->front = cur->front->front;
    }
}
char s[100001], op;
int n;
int main(){
    list=(List*)malloc(sizeof(List));
    list->head=list->tail=NULL;
    int i;
    char a;
    Node *cur=NULL;
     
    scanf("%s", s);
    scanf("%d", &n);
     
    int len=strlen(s);
     
    for(i=0;i<len;i++){
        cur = insert(cur,s[i]);
    }
    cur->front = list->tail;
    cur->back = NULL;
    for(i=0;i<n;i++){
        scanf(" %c", &op);
        if(op=='L'){
            //printf("LLLLL\n");
            if(cur->front==NULL) continue;
            cur->back = cur->front;
            cur->front = cur->back->front;
        }
        else if(op=='D'){
            //printf("DDDDD\n");
            if(cur->back==NULL) continue;
            cur->front = cur->back;
            cur->back = cur->front->back;
        }
        else if(op=='B'){
            //printf("BBBB\n");
            if(cur->front==NULL) continue;
            Delete(cur);
        }
        else{
            scanf(" %c", &a);
            Node *node=new_node(a);
            if(cur->front == NULL){
                node->back = cur->back;
                cur->back->front = node;
                cur->front = node;
                list->head = node;
            }else if(cur->back == NULL){
                node->front = list->tail;
                list->tail = node;
                cur->front = node;
            }else{
                node->front = cur->front;
                node->back = cur->back;
                cur->front->back = node;
                cur->back->front = node;
                cur->front = node;
            }
        }
    }
    cur=list->head;
    while(cur!=NULL){
        printf("%c",cur->data);
        cur=cur->back;
    }
}