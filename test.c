#include<stdio.h>
#include<time.h>

static int a = 1;
int* test(){
    static int a = 1;
    printf("%d\n",a);
    return &a;
    
}

int main(){
    static int a = 1;
    a = 2;
    printf("%d\n",a);
    int *p = test();
    printf("%p\n",p);
    return 0;
}