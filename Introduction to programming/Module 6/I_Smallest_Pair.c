#include<stdio.h>
#include<limits.h>

int main(){
    int t;
    scanf("%d", &t);

    int min_num = INT_MAX;

    while (t--)
    {
        int n;
        scanf("%d", &n);

        int arr[n];

        for (int i=0; i<n; i++)
        {
            scanf("%d", &arr[i]);
        }
        

        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                int value = arr[i] + arr[j] + (j - i);
                if (value < min_num) {
                    min_num = value;
                }

            }
            
        }

        printf("%d", min_num);
        
    }
    
    
    return 0;
}