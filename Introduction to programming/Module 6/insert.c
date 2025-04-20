#include<stdio.h>

int main(){
    int n;
    int idx, tar;
    scanf("%d", &n);

    int arr[n+1];

    for (int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d %d", &idx, &tar);

    for (int i=n; i>idx; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[idx] = tar;

    for (int i=0; i<n+1; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}