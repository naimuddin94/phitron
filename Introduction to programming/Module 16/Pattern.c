#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int hash = 1;
    int isHash = 1;


    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n-1; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < hash; j++)
        {
            if(isHash == 1){
                printf("#");
            }else{
                printf("-");
            }
        }
        
        printf("\n");
        hash+=2;
        if(isHash==1){
            isHash=0;
        }else{
            isHash=1;
        }
    }


    hash-=4;

    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < hash; j++)
        {
            if(isHash == 1){
                printf("#");
            }else{
                printf("-");
            }
        }
        
        printf("\n");
        hash-=2;
        if(isHash==1){
            isHash=0;
        }else{
            isHash=1;
        }
    }
    
    return 0;
}