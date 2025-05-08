#include<stdio.h>

int count_before_one(int a[], int size){
    for (int i = 0; i < size; i++)
    {
        if(a[i]==1){
            return i;
        }
    }

    return size;
}

int main(){
    int n;
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int ans = count_before_one(a, n);
    printf("%d", ans);
    
    return 0;
}