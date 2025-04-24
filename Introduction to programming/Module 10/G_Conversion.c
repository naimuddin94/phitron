#include<stdio.h>

int main(){
    char s[1000001];
    scanf("%s", &s);
    
    for (int i=0; s[i] != '\0' ; i++)
    {
        if(s[i] == ','){
            printf("%c", ' ');
        }else{
            if(s[i]<='Z' && s[i] >= 'A'){
                printf("%c", s[i]+32);
            }else if(s[i]<='z' && s[i] >= 'a'){
                printf("%c", s[i]-32);
            }
        }
    }
    
    return 0;
}