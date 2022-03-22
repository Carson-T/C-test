#include<stdio.h>
#include<string.h>
#include<time.h>
#include<malloc.h>

typedef struct Link{
    int elm;
    struct Link *next;
}*Linklist;

void createList(int *array, Linklist head){
    Linklist tmp = head;
    for(int i;i<9;i++){
        Linklist node = (Linklist)malloc(sizeof(Linklist));
        node->elm = *array;
        node->next = NULL;
        tmp->next = node;
        tmp = tmp->next;
        array++;
    }
    // return head;
}

void TraverseList(Linklist head){
    while(head->next){
        printf("%d ",head->next->elm);
        head = head->next;
    }
    
}

Linklist ReverseList(Linklist head){
    Linklist FirstPtr = NULL, SecPtr = NULL, TempPtr = NULL;
    FirstPtr = head->next;
    SecPtr = FirstPtr->next;
    FirstPtr->next = NULL;//将第一个结点指针置空
    while (SecPtr)
    {
        TempPtr = SecPtr->next;
        SecPtr->next = FirstPtr;
        FirstPtr = SecPtr;
        SecPtr = TempPtr;
    }
    head->next = FirstPtr;
    return head;
}

void InsertNode(Linklist head, int num, int newelm){
    Linklist newnode = (Linklist)malloc(sizeof(struct Link));
    for(int i=1;i<num;i++){
        head = head->next;
    }
    newnode->elm = newelm;
    newnode->next = head->next;
    head->next = newnode;
}

void DelNode(Linklist head, int num){
    for(int i=1;i<num;i++){
        head = head->next;
    }
    Linklist temp = head->next;
    head->next = temp->next;
    free(temp);
    temp = NULL;
}


int main(){
    int array[] = {1,2,3,4,5,6,7,8,9};
    Linklist head = (Linklist)malloc(sizeof(Linklist));
    createList(array,head);
    // InsertNode(head,1,10);
    // DelNode(head,5);
    TraverseList(head);
    printf("\n");
    head = ReverseList(head);
    TraverseList(head);
    free(head);
}