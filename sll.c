#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}*node;
node head=NULL, tail=NULL;

node insert_last(node head, int data){
    node nn = malloc(sizeof(struct node));
    nn->data=data;
    
    if(head==NULL){ head=tail=nn; return head; }
    else{
        tail->next = nn;
        tail=nn;
        return head;
    }
    
}

node delete_last(node head){
    node temp = head;
    if(head==NULL) return NULL;
    if(head->next == NULL){
        free(head);
        head=tail=NULL;
        return head;
    }

    while(temp->next->next!=NULL) temp=temp->next;
    free(temp->next);
    temp->next = NULL;
    tail = temp;

    return head;
}

void print(){
    node temp = head;
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("null");
}

int main(){
    head=insert_last(head, 45);
    head=insert_last(head, 30);
    head=insert_last(head, 97);

    print();

    head=delete_last(head);
    printf("\n");
    print();


    return 0;
}