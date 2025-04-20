#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int min_idx = 0, max_idx = 0;

    int arr[n];

    for (int i=0; i<n; i++)
    {
       scanf("%d", &arr[i]);
       if(arr[i] > arr[max_idx]){
        max_idx = i;
       }
       if(arr[i] < arr[min_idx]){
        min_idx = i;
       }
    }

    int tmp = arr[min_idx];
    arr[min_idx] = arr[max_idx];
    arr[max_idx] = tmp;

    for (int i=0; i<n; i++)
    {
       printf("%d ", arr[i]);
    }  

    return 0;
}