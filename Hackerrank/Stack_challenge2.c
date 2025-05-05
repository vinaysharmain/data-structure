#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
# define MAX 100
int stack[MAX],top=-1;
int push(int value){
    return stack[++top]=value;
}
int pop(){
    return stack[top--];
}
void display(){
for(int i=top;i>=0;i--){
    printf("%d ", stack[i]);
}
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d", &a);
        push(a);
    }
    for(int i=0;i<2;i++){
        pop();
    }
    for(int i=0;i<4;i++){
        int b;
        scanf("%d", &b);
        push(b);
    }
    pop();
    for(int i=0;i<2;i++){
        int c;
        scanf("%d", &c);
        push(c);
    }
    for(int i=0;i<3;i++){
        pop();
    }
    display();
    return 0;
}
