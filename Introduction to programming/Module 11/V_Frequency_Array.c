#include<stdio.h>

int main(){
    int x, y;
    scanf("%d %d", &x, &y);

    int arr[x];

    for (int i=0; i<x; i++)
    {
        scanf("%d", &arr[i]);
    }

    int fre[y+1];

    for (int i=0; i<=y; i++)
    {
        fre[i] = 0;
    }

    for (int i=0; i<y; i++)
    {
        fre[i] = 0;
    }

    for (int i=0; i<x; i++)
    {
        fre[arr[i]]++;
    }


    for (int i=1; i<=y; i++)
    {
        printf("%d\n", fre[i]);
    }
    

    return 0;
}