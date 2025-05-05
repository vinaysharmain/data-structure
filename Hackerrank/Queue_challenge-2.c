#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void nextgreater(int arr[],int n){
    int result[n];
    int stack[n];
    int top=-1;
    for(int i=0;i<n;i++){
        result[i]=-1;
    }
    for(int i=0;i<2*n;i++){
        int index=i%n;
        while(top!=-1 && arr[index]>arr[stack[top]]){
            result[stack[top]]=arr[index];
            top--;
        }
        if(i<n)
            stack[++top]=index;
    }
    for(int i=0;i<n;i++){
        printf("%d ", result[i]);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    nextgreater(arr,n);
    return 0;
}
