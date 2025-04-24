#include <stdio.h>
#include <string.h>

int main() {
    char s[1001];
    scanf("%s", s);

    int i = 0;
    int j = strlen(s) - 1;
    int isPalindrome = 1; // Assume it's a palindrome

    while (i < j) {
        if (s[i] != s[j]) {
            isPalindrome = 0;
            break;
        }
        i++;
        j--;
    }

    if (isPalindrome)
        printf("YES");
    else
        printf("NO");

    return 0;
}
