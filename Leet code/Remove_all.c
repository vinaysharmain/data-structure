int removeElement(int* arr, int numsSize, int val) {
    int count=0;
    for(int i=0;i<numsSize;i++){
        if(arr[i]!=val){
            arr[count++]=arr[i];
        }
    }
    return count;
}
