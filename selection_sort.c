#include<stdio.h>
#define LEN 10


void sort(int array[]){
    int temp;
    for(int i=0; i<LEN-1; i++){
        int min = i;
        for(int j = i+1; j<LEN;j++){
            if(array[j]<array[min]){
                min = j;
            }
        }
        if(min!=i){
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
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