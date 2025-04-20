#include<stdio.h>

int main(){
    int n, x, pos_total=0, neg_total=0;
    scanf("%d", &n);

    int arr[n];

    
    for (int i=0; i<n; i++)
    {
        scanf("%d", &x);
        if(x>0){
            pos_total += x;
        }else{
            neg_total += x;
        }
    }

    printf("%d %d", pos_total, neg_total);

    return 0;
}