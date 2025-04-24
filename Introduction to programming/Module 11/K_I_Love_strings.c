#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N); 

    for (int t = 0; t < N; t++) {
        char S[51], T[51];
        scanf("%s %s", S, T);

        int lenS = strlen(S);
        int lenT = strlen(T);
        int minLen = lenS < lenT ? lenS : lenT;

       
        for (int i = 0; i < minLen; i++) {
            printf("%c%c", S[i], T[i]);
        }

        if (lenS > lenT) {
            printf("%s", &S[minLen]);
        } else if (lenT > lenS) {
            printf("%s", &T[minLen]);
        }

        printf("\n"); 
    }

    return 0;
}
