#include<stdio.h>

int main(){
    int n, x;
    scanf("%d", &n);

    int arr[n];

    for (int i=0; i<n; i++)
    {
        scanf("%d", &x);

        if(x>0){
            arr[i] = 1;
        }else if(x<0){
            arr[i] = 2;
        }else{
            arr[i] = 0;
        }
    }

    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}