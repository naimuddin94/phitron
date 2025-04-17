#include<stdio.h>

int main(){
    int t;
    scanf("%d", &t);

    for (int i=1; i<=t; i++)
    {
        int n;
        long long int res = 1;
        scanf("%d", &n);
        if(n==0 || n==1){
            printf("%lld\n", res);
        }else{
            for (int i=2; i<=n; i++)
            {
                res *= i;
            }
            printf("%lld\n", res);
        }
    }

    return 0;
}