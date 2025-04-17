#include<stdio.h>

int main(){
    
    int n;
    scanf("%d", &n);

    int res = -1;
    int target;

    int arr[n];

    for (int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &target);

    for (int i=0; i<n; i++)
    {
        if(arr[i] == target){
            res = i;
            break;
        }
    }
    
    printf("%d", res);

    return 0;
}