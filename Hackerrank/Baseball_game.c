int calPoints(char** S, int n) {
    int stack[n],top=-1,i;
    for(int i=0;i<n;i++){
        if(strcmp(S[i],"+")==0){
            stack[++top]=stack[top]+stack[top-1];
        }
        else if(strcmp(S[i],"C")==0){
            top--;
        }
        else if(strcmp(S[i],"D")==0){
            stack[++top]=stack[top]*2;
        }
        else{
            stack[++top]=atoi(S[i]);
        }
    }
    int sum=0;
    while(top!=-1){
        sum+=stack[top--];
    }
    return sum;
}
