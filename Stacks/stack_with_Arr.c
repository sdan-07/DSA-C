#include<stdio.h>
#include<stdlib.h>
#define max 5

typedef struct stack{
    int Top;
    int stk[max];
}*stack;
static stack s =NULL;

stack create_stack(){
    if(s==NULL){
        s = malloc(sizeof(struct stack));

        if(!s){
            printf("ERROR cant create stack");
            exit(1);
        }

        s->Top = -1;
    }
    
    return s;
}

void cleanup_stack(){
    if (s!=NULL){
        free(s);
        s=NULL;
        printf("\nStack freed\n");
    }
    else printf("\nStack doesn't exist\n");
}


int is_full(stack s){ return (s->Top == max - 1); }

int is_empty(stack s){ return (s->Top == - 1); }

void peek() { printf("\nPEEK: %d\n",s->stk[s->Top]); }


void push(int E){
    create_stack();

    if(!is_full(s)){
        s->stk[++(s->Top)] = E;
    }
    else printf("Stack already full");
}

void pop(){
    create_stack();

    if(!is_empty(s)){
        printf("\nPopped element: %d", s->stk[s->Top]);
        s->stk[(s->Top)--];
    }
    else printf("Stack already empty");
}


void print(stack s){
    create_stack();

    int i = s->Top;
    printf("\nStack contents:\n");

    while(i >= 0){
        printf("%d\n",s->stk[i]);
        i--;
    }
}


int main(){
    push(12);
    push(95);
    push(76);
    pop();
    peek();

    print(s);


    return 0;
}