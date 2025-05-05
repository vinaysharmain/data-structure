bool isValid(char* s) {
    int top=-1;
    int len=strlen(s);
    char stack[len];
    char ch;
    for(int i=0;i<len;i++){
        ch=s[i];
        if(ch=='(' || ch=='{' || ch=='['){
            stack[++top]=ch;
        }
        else if(ch==')' || ch=='}' || ch==']'){
            if(top==-1) return false;
           else if (stack[top]=='(' && ch!=')') return false;
           else if (stack[top]=='{' && ch!='}') return false;
           else if (stack[top]=='[' && ch!=']') return false;
           top--;
        }
    }
if (top==-1) return true;
else return false;
}
