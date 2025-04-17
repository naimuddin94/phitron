#include<stdio.h>

int main(){
    int x,y;
    int res = 0;

    scanf("%d %d", &x, &y);

    if(x<y){
        while (x<y)
        {
            if(x%2==1){
                res += x;
            }
            x++;
        }
    }else{
        while (x>y)
        {
            if(x%2==1){
                res += x;
            }
            x--;
        }
    }

    printf("%d\n", res);
    

    return 0;
}