#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int* getRow(int rowIndex, int* returnSize){
    int *p = malloc(sizeof(int));
    p[0] = 1;
    int *q;
    for(int i=1;i<=rowIndex;i++){
        q = malloc(sizeof(int)*(i+1));
        q[0] = 1;
        q[i] = 1;
        for(int j=1;j<i;j++){
            q[i] = p[j-1]+p[j];
        }
        free(p);
        p = q;
    }
    *returnSize = rowIndex+1;
    return p;
}
int main(){
    int *returnSize = malloc(sizeof(int));
    int row = 2;
    int *p = getRow(row,returnSize);
    for(int i=0;i<row+1;i++){
        printf("%d ",p[i]);;
    }
    free(returnSize);
    free(p);
    return 0;
}