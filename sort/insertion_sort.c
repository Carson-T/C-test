#include<stdio.h>
#define LEN 10

void sort(int array[]){
    int temp;
    int j;
    for(int i=1;i<LEN;i++){
        temp = array[i];
        for(j=i;j>0 && array[j-1]>temp;j--){
            array[j] = array[j-1];
        }
        array[j] = temp;
    }
}
int main(int argc, char* argv[]){
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