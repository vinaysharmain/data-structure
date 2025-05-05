//Write a program to convert an infix expression to its corresponding postfix and prefix expressions and vice-versa.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int precedence(char opr){
    switch(opr){
        case'+': case '-': return 1;
        case'*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}
char *infixTopostfix(char *exp){
    int size = strlen(exp),top=-1,index=0;
    char operator[size];
    char *str=(char*)malloc(size+1);
    for(int i=0;i<size;i++){
        char ch=exp[i];
        if(isdigit(ch) || isalpha(ch))
        str[index++]=ch;
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
            if(top==-1)
            operator[++top]=ch;
            else{
                while(top!=-1 && precedence(ch)<=precedence(operator[top])){
                    str[index++]=operator[top--];
                }
                operator[++top]=ch;
            }
        }
        else if(ch=='(')
        operator[++top]=ch;
        else if(ch==')'){
            while(operator[top]!='('){
                str[index++]=operator[top--];
            }
            top--;
        }
    }
    while(top!=-1){
        str[index++]=operator[top--];
    }
    str[index]='\0';
    return str;
}
char *infixToprefix(char *exp){
    int size = strlen(exp),top=-1,index=0;
    char operator[size];
    char *str=(char*)malloc(size+1);
    for(int i=size-1;i>=0;i--){
        char ch=exp[i];
        if(isdigit(ch) || isalpha(ch))
        str[index++]=ch;
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
            if(top==-1)
            operator[++top]=ch;
            else{
                while(top!=-1 && precedence(ch)<precedence(operator[top])){
                    str[index++]=operator[top--];
                }
                operator[++top]=ch;
            }
        }
        else if(ch==')')
        operator[++top]=ch;
        else if(ch=='('){
            while(operator[top]!='('){
                str[index++]=operator[top--];
            }
            top--;
        }
    }
    while(top!=-1){
        str[index++]=operator[top--];
    }
    str[index]='\0';
    return strrev(str);
}
char *postfixToinfix(char *exp){
    int size=strlen(exp),top=-1;
    char stack[size][100];
    for(int i=0;i<size;i++){
        char ch=exp[i];
        if(isalnum(ch)){
            char temp[]={ch,'\0'};
            strcpy(stack[++top],temp);
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
            char *s1=stack[top--];
            char *s2=stack[top--];
            char temp[100];
            snprintf(temp,100,"(%s%c%s)", s2, ch, s1);
            strcpy(stack[++top], temp);
        }
    }
    char *s=stack[top];
    return s;
}
char *prefixToinfix(char *exp){
    int size=strlen(exp),top=-1;
    char stack[size][100];
    for(int i=size-1;i>=0;i--){
        char ch=exp[i];
        if(isalnum(ch)){
            char temp[]={ch,'\0'};
            strcpy(stack[++top],temp);
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
            char *s1=stack[top--];
            char *s2=stack[top--];
            char temp[100];
            snprintf(temp,100,"(%s%c%s)", s1, ch, s2);
            strcpy(stack[++top], temp);
        }
    }
    char *s=stack[top];
    return s;
}
int main(){
    char exp[100];
    printf("Enter Infix expression: ");
    fgets(exp,sizeof(exp),stdin);
    printf("Postfix form is: %s\n", infixTopostfix(exp));
    printf("Prefix form is: %s\n", infixToprefix(exp));
    printf("Enter postfix Expression: ");
    gets(exp);
    printf("Infix form is %s\n", postfixToinfix(exp));
    printf("Enter prefix Expression: ");
    gets(exp);
    printf("Infix form is %s\n", prefixToinfix(exp));
    return 0;
}
