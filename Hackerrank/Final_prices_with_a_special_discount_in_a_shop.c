/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    *returnSize=pricesSize;
    int *result=(int*) malloc(pricesSize*sizeof(int));
    for(int i=0;i<pricesSize;i++){
        result[i]=prices[i];
        for(int j=i+1;j<pricesSize;j++){
            if(prices[j]<=result[i]){
                result[i]=prices[i]-prices[j];
                break;
            }
        }
    }
    return result;
    free(returnSize);
}
