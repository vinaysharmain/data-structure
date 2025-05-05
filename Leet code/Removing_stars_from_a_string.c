char* removeStars(char* s) {
    int len=strlen(s),top=-1;
    char *stack=(char*)malloc((len+1)*sizeof(char));
    for(int i=0;i<len;i++){
        if(s[i]=='*'){
            if(top>=0) top--;
        }
        else{
            stack[++top]=s[i];
        }
    }
    stack[top+1]='\0';
    return stack;
}
