#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
# define MAX 100
int stack[MAX];
int top=-1;
int push(int value){
    if(top<MAX-1)
    return stack[++top]=value;
    else return 0;
}
int pop(){
    if(top>-1)
    return stack[top--];
    else return 0;
}
void display(){
    for(int i=top;i>=0;i--){
        printf("%d ", stack[i]);
    }
}
int main() {
    for(int i=0;i<3;i++){
        int a;
        scanf("%d", &a);
        push(a);
    }
    pop();
    for(int i=0;i<2;i++){
        int a;
        scanf("%d", &a);
        push(a);
    }
    for(int i=0;i<3;i++){
        pop();
    }
    display();
    return 0;
}
