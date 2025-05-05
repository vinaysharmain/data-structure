/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* arr, int n, int target, int* returnSize) {
    *returnSize=2;
    int* result=(int*)calloc(2,sizeof(int));
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target){
            result[0]=i;
            result[1]=j;
            return result;
            }
        }
    }
    *returnSize=0;
    return 0;
}
