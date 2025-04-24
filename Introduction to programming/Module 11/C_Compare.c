#include<stdio.h>
#include<string.h>

int main(){
    char x[21], y[21];
    scanf("%s %s", &x, &y);

    int res = strcmp(x, y);

    if(res<0){
        printf("%s", x);
    }else if(res>=0){
        printf("%s", y);
    }
    
    return 0;
}