#include<stdio.h>
#include<string.h>
#include<time.h>

struct Person{
    int age;
    char name[6];
};
int main(){
    struct Person person1;
    person1.age = 10;
    printf("%d",person1);
    return 0;
}