#include<stdio.h>
#define LEN 10

int sort(int array[]){
    int temp;
    for(int i=0;i<LEN-1;i++){
        for(int j=0;j<LEN-1-i;j++){
            if(array[j]>array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    return 0;
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