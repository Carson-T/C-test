#include<stdio.h>
#include<stdlib.h>

typedef struct LinkStack{
    char elm;
    struct LinkStack *next;
}linkstack;

void push(linkstack **top,char elm){
    linkstack* node = (linkstack*)malloc(sizeof(linkstack));
    node->elm = elm;
    node->next = (*top);
    (*top) = node;
}

char pop(linkstack** top){
    linkstack *p = (*top);
    char output_elm;
    if(p){
        output_elm = p->elm;
        printf("%c\n",output_elm);
    }else{
        printf("Linkstack is empty\n");
        output_elm = '\0';
    }
    (*top) = p->next;
    free(p);
    return output_elm;
}

int main(){
    linkstack *top = NULL;
    push(&top,'a');
    push(&top,'b');
    push(&top,'c');
    push(&top,'d');
    char c;
    c = pop(&top);
    c = pop(&top);
    c = pop(&top);
    c = pop(&top);
    c = pop(&top);
    return 0;
}   