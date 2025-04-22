#include <stdio.h>
#include<limits.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        int A[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        int min_val = INT_MAX;

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int value = A[i] + A[j] + (j - i);
                if (value < min_val) {
                    min_val = value;
                }
            }
        }

        printf("%d\n", min_val);
    }

    return 0;
}
