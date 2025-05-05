#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int stack[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &stack[i]);
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (stack[i] < stack[j]) {
                int temp = stack[i];
                stack[i] = stack[j];
                stack[j] = temp;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", stack[i]);
    }
    return 0;
}
