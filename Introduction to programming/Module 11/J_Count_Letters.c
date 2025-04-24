#include <stdio.h>
#include <stdlib.h>

int main() {
    char *s = (char *)malloc(10000001 * sizeof(char));
    if (s == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    scanf("%s", s);

    int fre[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        fre[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (fre[i] > 0) {
            printf("%c : %d\n", 'a' + i, fre[i]);
        }
    }

    free(s);
    return 0;
}
