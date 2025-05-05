#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n,target;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &target);
    for(int i=0;i<n;i++){
        if(target==arr[i]){
            for(int j=i;j<n;j++){
                arr[j]=arr[j+1];
            }
            n--;
            break;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
