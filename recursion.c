#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*

        1,  n = 0
P_n(x)= 2x, n=1
        2xP_(n-1)(x)-2(n-1)P_(n-2), n>1

*/

int test(int n,int x){  //递归实现
    if(n==0)
        return 1;
    if(n==1)
        return 2*x;
    else
        return 2*x*test(n-1,x)-2*(n-1)*test(n-2,x);
    
}

struct Stack{
    int n;
    int P;
};

int Pfeidigui(int n,int x){   //使用栈实现非递归计算
    struct Stack mystack[10];
    int top = -1;
    for(int i=n;i>=0;i--){
        mystack[++top].n = i;
    }
    int low = top--;
    int high = top--;
    mystack[low].P = 2*x;
    mystack[high].P = 1;
    while(top>=0){
        mystack[top].P = 2*x*mystack[low].P-2*(mystack[top].n-1)*mystack[high].P;
        low--;
        high--;
        top--;
    }
    return mystack[0].P;
}

int main(){
    int a = Pfeidigui(2,3);
    printf("%d",a);
}