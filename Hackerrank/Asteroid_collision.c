/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int size, int* returnSize) {
    int top=-1;
    int *stack=(int *)malloc(size*sizeof(int));
    for(int i=0;i<size;i++){
        int current=asteroids[i];
        while(top>=0 && current<0 && stack[top]>0){
            if(abs(current)>stack[top]){
            top--; 
            }
            else if(abs(current)==stack[top]){
                current=0; top--;
                break;
            }
            else{
                current=0; 
                break;
            }
        }
        if(current!=0)
        stack[++top]=current;
    }
    *returnSize=top+1;
    return stack;
}
