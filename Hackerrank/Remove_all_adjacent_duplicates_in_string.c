#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char stack[100];
    int top=-1;
    fgets(stack,sizeof(stack),stdin);
    int len=strlen(stack);
    for(int i=0;i<len;i++){
        char ch=stack[i];
        if(ch==stack[top] && top!=-1){
            stack[--top];
        }
        else{
            stack[++top]=ch;
        }
    }
    for(int i=0;i<=top;i++){
        printf("%c", stack[i]);
    }
    return 0;
}
