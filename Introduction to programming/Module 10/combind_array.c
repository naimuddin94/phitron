#include<stdio.h>

int main(){
    int x;
    scanf("%d", &x);
    int a[x];
    for(int i=0; i<x; i++){
        scanf("%d", &a[i]);
    }

    int y;
    scanf("%d", &y);
    int b[y];
    for(int i=0; i<y; i++){
        scanf("%d", &b[i]);
    }

    int c[x+y];

    for(int i=0; i<x; i++){
        c[i] = a[i];
    }

    for(int i=0; i<y; i++){
        c[x+i] = b[i];
    }

    for(int i=0; i<x+y; i++){
        printf("%d ", c[i]);
    }

    return 0;
}