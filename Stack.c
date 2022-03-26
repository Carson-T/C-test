#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20


typedef struct Stack{
    int data[MAXSIZE];
    int top;
}st;

void init_stack(st *stack){
    (*stack).top = -1;
}

void push(st *stack, int elm){
    if((*stack).top<MAXSIZE-1){
        (*stack).data[++(*stack).top] = elm;
    }
    else{
        printf("stack is overflow");
    }
}

void pop(st *stack,int *a){
    if((*stack).top>=0){
        *a = (*stack).data[(*stack).top--];
    }
}

int main(){
    st mystack;
    init_stack(&mystack);
    // printf("%d",mystack.top);
    for(int i=0;i<10;i++){
        push(&mystack,i);
    }
    int a;
    while(mystack.top>-1){
        pop(&mystack,&a);
        printf("%d ",a);
    }
    char *d = "asdf";
    char *p = d;
    char *q = d;
    // *p = 'q';
    printf("%p %p",p,q);
    return 0;
}