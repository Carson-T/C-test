#include<stdio.h>
#include<malloc.h>
#define MAX 10
#define AAA char
void aaa(int **p){
    int b = 2;
    *p = &b;
    printf("%p\n",*p);
}

struct person{
    int a;
}p,q;

int main(){
    int a = 1;
    int *p = &a;
    printf("%p\n",p);
    aaa(&p);
    printf("%p\n",p);
    char c[100];
    scanf("%s %d",&c,&a);
    printf("%s %d",c,a);
    return 0;
}