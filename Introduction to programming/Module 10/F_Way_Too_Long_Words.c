#include<stdio.h>
#include<string.h>

int main(){
    int t;
    scanf("%d", &t);

    while (t>0)
    {
        char s[101];
        scanf("%s", &s);

        if(strlen(s)<=10){
            printf("%s\n", s);
        }else{
            printf("%c%d%c\n", s[0], strlen(s)-2, s[strlen(s)-1]);
        }
        t--;
    }
    
    return 0;
}