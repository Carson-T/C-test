#include<stdio.h>
#include<malloc.h>
#define MAX 10

void aaa(int **p){
    int b = 2;
    *p = &b;
    printf("%p\n",*p);
}

int main(){
    int a = 1;
    int *p = &a;
    printf("%p\n",p);
    aaa(&p);
    printf("%p\n",p);
    return 0;

}