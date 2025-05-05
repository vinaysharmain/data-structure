int timeRequiredToBuy(int* arr, int n, int k) {
    int count=0;
    while(arr[k]>0){
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                arr[i]-=1;
                count++;
            }
            if(arr[k]==0) break;
        }
    }
    return count;
}
