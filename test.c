#include<stdio.h>
#include<string.h>
#include<time.h>
#include<malloc.h>

struct Link{
    int age;
    struct Link *next;
};

struct Link* createList(int *array){
    struct Link * p;
    p = (struct Link*)malloc(4);
    struct Link* head = p;
    for(int i;i<9;i++){
        struct Link* node = (struct Link*)malloc(sizeof(struct Link));
        head->next = node;
        head->age = *array;
        head = node;
        head->next = NULL;
        array++;
    }
    return p;
}

void TraverseList(struct Link* head){
    while(head->next){
        printf("%d\n",head->age);
        head = head->next;
    }
    
}

void InsertNode(struct Link* head, int num, int newage){
    struct Link *newnode = (struct Link*)malloc(sizeof(struct Link));
    for(int i=1;i<num;i++){
        head = head->next;
    }
    newnode->age = newage;
    newnode->next = head->next;
    head->next = newnode;
}


int main(){
    int array[] = {1,2,3,4,5,6,7,8,9};
    struct Link* head = createList(array);
    printf("%d\n",(*head).age);
    InsertNode(head,3,10);
    TraverseList(head);
    free(head);
}