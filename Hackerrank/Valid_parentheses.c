#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int check(char *str){
    int top=-1;
    char ch;
    int len=strlen(str);
    char stack[len];
    for(int i=0;i<len;i++){
        ch=str[i];
        if(ch=='(' || ch=='[' || ch=='{'){
            stack[++top]=ch;
        }
        else if(ch==')' || ch==']' || ch=='}'){
            if(top==-1) return 0;
            else if(stack[top]=='(' && ch!=')')
            return 0;
            else if(stack[top]=='{' && ch!='}')
            return 0;
            else if(stack[top]=='[' && ch!=']')
            return 0;
            top--;
        }
    }
    if(top==-1) return 1;
    else return 0;
}
int main(){
    char str[100];
    fgets(str,sizeof(str),stdin);
    if(check(str)){
        printf("True");
    }
    else{
        printf("False");
    }
    return 0;
}
