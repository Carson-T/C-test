#include<stdio.h>
#define MAX 10
int main(){
    int a[MAX];
    for(int i=0;i<MAX;i++){
        a[i] = i*2;
    }
    int* ptr = a;
    for(;ptr<=&a[MAX-1];ptr++){
        printf("%d\n",*ptr);
    }
    ptr = NULL;
    char s = 'a';
    printf("%s",s);
    return 0;
}