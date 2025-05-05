int evalRPN(char** s, int n) {
    int stack[10000],top=-1;
    for(int i=0;i<n;i++){
    if(strlen(s[i])==1 && (*s[i]<'0' || *s[i]>'9')){
        int a=stack[top--];
        int b=stack[top--];
        int z;
        switch(s[i][0]){
            case '+': z=b+a; break;
            case '-': z=b-a; break;
            case '/': z=b/a; break;
            case '*': z=b*a; break;
        }
        stack[++top]=z;
    }
    else{
        stack[++top]=atoi(s[i]);
    }
}
return stack[top];
}
