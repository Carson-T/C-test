#include<stdio.h>
#define LEN 10

void sort(int array[]){
    int temp;
    int j;
    for(int gap = LEN>>1; gap>0; gap = gap>>1){
        for(int i = gap; i<LEN; i++){
            temp = array[i];
            for(j=i-gap;j>=0 && array[j]>temp;j -= gap){
                array[j+gap] = array[j];
            }
            array[j+gap] = temp;
        }
    }
}

int main(int argc, char *argv[]){
    printf("This is a %s program\n",argv[1]);
    int array[LEN] = {12,65,23,95,18,35,90,34,11,99};
    for(int i=0;i<LEN;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    sort(array);
    for(int i=0;i<LEN;i++){
        printf("%d ",array[i]);
    }
}