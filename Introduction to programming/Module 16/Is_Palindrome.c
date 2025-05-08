#include<stdio.h>
#include<string.h>

int is_palindrome(char s[]){
    int isPalindrome = 1;

    int i=0;
    int j = strlen(s)-1;
    
    while (i<j)
    {
        
        if(s[i] != s[j]){
            isPalindrome = 0;
            break;
        }

        i++;
        j--;
    }

    return isPalindrome;
}

int main(){
    char s[1001];
    scanf("%s", s);
    
    int ans = is_palindrome(s);

    if(ans){
        printf("Palindrome");
    }else{
        printf("Not Palindrome");
    }
    
    return 0;
}