#include<stdio.h>
#include<string.h>

int main(){
    char x[11], y[11];
    scanf("%s", x);
    scanf("%s", y);

    

    int x_len = strlen(x);
    int y_len = strlen(y);

    char new_arr[x_len+y_len+1];

    printf("%d %d\n", x_len, y_len);

    for (int i=0; i<x_len; i++)
    {
        new_arr[i] = x[i];
    }

    for (int i=0; i<y_len; i++)
    {
        new_arr[x_len+i] = y[i];
    }

    new_arr[x_len + y_len] = '\0';

    printf("%s\n", new_arr);

    char tmp = x[0];
    x[0] = y[0];
    y[0] = tmp;
    
    printf("%s ", x);
    printf("%s", y);

    return 0;
}