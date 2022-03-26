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
    Linklist p = head;
    while(p->next){
        printf("%d ",p->next->elm);
        p = p->next;
    }
    
}

Linklist ReverseList(Linklist head){
    Linklist FirstPtr = NULL, SecPtr = NULL, TempPtr = NULL;
    FirstPtr = head->next;
    SecPtr = FirstPtr->next;
    FirstPtr->next = NULL;
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

void InsertSort(Linklist head){    //直接插入递增排序
    Linklist tmp;
    Linklist p = head->next;
    Linklist q = p->next;
    p->next = NULL;
    p = q;
    while(p!=NULL){
        tmp = head;
        q = p->next;
        while(tmp->next!=NULL && p->elm>tmp->next->elm){
            tmp = tmp->next;
        }
        p->next = tmp->next;
        tmp->next = p;
        p = q;
    }
}

int main(){
    int array[] = {23,32,3,41,25,33,7,12,39};
    Linklist head = (Linklist)malloc(sizeof(Linklist));
    createList(array,head);
    // InsertNode(head,1,10);
    // DelNode(head,5);
    TraverseList(head);
    printf("\n");
    InsertSort(head);
    TraverseList(head);
    printf("\n");
    head = ReverseList(head);
    TraverseList(head);
    free(head);
}