#include<stdio.h>

void pass_by_value(int* a){
    printf("Inside function: %p\n", &*a);
    *a = 20;
}

int main(){
    int a = 10;

    printf("Address of a in main: %p\n", &a); // Address of a in main
    pass_by_value(&a);
    printf("Address of a in main: %p\n", &a); // Address of a in main


    return 0;
}