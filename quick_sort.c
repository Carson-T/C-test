#include<stdio.h>
#define LEN 10
void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}

void sort(int array[],int start,int end){
    if(start >= end)
        return;
    int mid = array[end];
    int low = start;
    int high = end-1;
    while(low<high){
        while(array[low]<mid && low<high){
            low++;
        }
        while(array[high]>=mid && low<high){
            high--;
        }
        swap(&array[low],&array[high]);
    }
    if(array[low] >= array[end])
        swap(&array[low],&array[end]);
    else  
        low++;
    if(low)
        sort(array,start,low-1);
    sort(array,low+1,end);
}

int main(int argc, char *argv[]){
    printf("This is a %s program\n",argv[1]);
    int array[LEN] = {12,65,23,95,18,35,90,34,11,99};
    for(int i=0;i<LEN;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    sort(array,0,LEN-1);
    for(int i=0;i<LEN;i++){
        printf("%d ",array[i]);
    }
}