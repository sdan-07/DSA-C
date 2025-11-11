#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}*node;
node head=NULL, tail=NULL;

node insert_last(node head, int data){
    node nn = malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    
    if(head==NULL){ head=tail=nn; return head; }
    else{
        tail->next = nn;
        nn->prev = tail;
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

node reverse(node head){
    if(head == NULL) return NULL;
    if(head->next ==  NULL) return head;

    node curr = head, prevNode = NULL;

    while(curr!=NULL){
        node nextNode = curr->next;
        curr->next = prevNode;
        prevNode = curr;
        curr = nextNode;
    }

    return prevNode;
}

void print(){
    node temp = head;
    while(temp!=NULL){
        printf("%d <-> ", temp->data);
        temp=temp->next;
    }
    printf("null");
}

int main(){
    head=insert_last(head, 47);
    head=insert_last(head, 25);
    head=insert_last(head, 85);
    head=insert_last(head, 55);
    print();

    head=delete_last(head);
    printf("\nAfter deleting:\n");
    print();

    head=reverse(head);
    printf("\nAfter reversing:\n");
    print();

    return 0;
}