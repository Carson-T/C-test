#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define NODE_NUM 10

typedef struct BTNoderee{
    int elm;
    struct BTNoderee *lchild, *rchild;
}*BTNode;


void CreateBTree(BTNode root,int data[]);
void InsertNode(BTNode root,int data);
void PreOrder(BTNode root);
void InOrder(BTNode root);
void PostOrder(BTNode root);
void visit(BTNode node);

void CreateBTree(BTNode root,int data[]){
    BTNode p = root;
    p->elm = data[0];
    p->lchild = NULL;
    p->rchild = NULL;
    for(int i=1;i<NODE_NUM;i++){
        InsertNode(p,data[i]);
    }
}


void InsertNode(BTNode root,int data){
    BTNode parent,p = root;
    while(p){
        parent = p;
        if(p->elm>data){
            p = p->lchild;
        }
        else
            p = p->rchild;    
    }
    BTNode newnode = (BTNode)malloc(sizeof(BTNode));
    newnode->elm = data;
    newnode->lchild = NULL;
    newnode->rchild = NULL;

    if(parent->elm>newnode->elm){
        parent->lchild = newnode;
    }
    else
        parent->rchild = newnode;
}

void visit(BTNode node){
    printf("%d ",node->elm);
}

void PreOrder(BTNode root){
    if(root){
        visit(root);
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}

void InOrder(BTNode root){
    if(root){
        InOrder(root->lchild);
        visit(root);
        InOrder(root->rchild);
    }
}

void PostOrder(BTNode root){
    if(root){
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        visit(root);
    }
}


int main(){
    BTNode root = (BTNode)malloc(sizeof(BTNode));
    int data[] = {1,2,3,4,5,6,7,8,9,10};
    CreateBTree(root,data);
    PreOrder(root);
    printf("\n");
    InOrder(root);
    printf("\n");
    PostOrder(root);
    return 0;

}