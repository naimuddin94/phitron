#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int i=0;
    int j=n-1;
    while (i<j)
    {
        if(arr[i] != arr[j]){
            printf("NO");
            break;
        }
        if(i==n/2-1){
            printf("YES");

        }
        i++;
        j--;
    }
    
    
    return 0;
}