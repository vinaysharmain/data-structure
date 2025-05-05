char* removeDuplicates(char* s) {
    int len=strlen(s);
    char* stack = (char*)malloc((len + 1) * sizeof(char));
    int top=-1;
    for(int i=0;i<len;i++){
        char ch=s[i];
        if(top!=-1 && ch==stack[top])
        stack[top--];
        else
        stack[++top]=ch;
    }
    stack[++top]='\0';
    return stack;
}
