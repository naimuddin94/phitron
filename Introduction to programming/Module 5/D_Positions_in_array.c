#include<stdio.h>

int main(){
    int n, x;
    scanf("%d", &n);

    int arr[n];

    for (int i=0; i<n; i++)
    {
        scanf("%d", &x);
        if(x<=10){
            printf("A[%d] = %d\n", i, x);
        }
    }
    
    return 0;
}