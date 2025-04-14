#include<stdio.h>

int main(){
    int n;
    int x;

    scanf("%d", &n);

    for(int i=0; i<=n; i++){
        scanf("%d", &x);
        printf("%d\n", x);
    }
    
    return 0;
}