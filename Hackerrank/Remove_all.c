#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n,t,newsize=0;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
      scanf("%d", &arr[i]);
    }
    scanf("%d", &t);
    for(int i=0;i<n;i++){
        if(arr[i]!=t){
            arr[newsize++]=arr[i];
        }
    }
    for(int i=0;i<newsize;i++){
    printf("%d ", arr[i]);
    }
    return 0;
}
