#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", &n);
    int list[n];
    for(int i=0;i<n;i++){
        scanf("%d", &list[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d ", list[i]);
    }
    return 0;
}
