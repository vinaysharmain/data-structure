#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n,target;
    scanf("%d", &n);
    int list[n];
    for(int i=0;i<n;i++){
        scanf("%d", &list[i]);
    }
    scanf("%d", &target);
    for(int i=0;i<n;i++){
        if(target==list[i]){
            printf("Found");
            return 0;
        }
    }
    printf("Not Found");
    return 0;
}
