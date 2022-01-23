#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *getRandom(){
    static int r[10];
    int i;
    for(i=0;i<10;i++){
        r[i] = i;
    }
    return r;
}

int main(){
    int p;
    int i;
    p = getRandom();
    for(i=0;i<10;i++){
        printf("%d\n",p+i);
    }
    return 0;
}