//Implement a Binary Search Tree using Array and develop functions to perform traversal, searching, insertion and deletion operations.
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int tree[SIZE];
int size=0;
void initialize(){
    for(int i=0;i<SIZE;i++)
        tree[i]=-1;
}
void insert(int root,int value){
    if(root>=SIZE){
        printf("Tree is full!!!\n");
    }
    else if(tree[root]==-1)
        tree[root]=value;
    else if(value<tree[root])
    insert(2*root+1,value);
    else if(value>tree[root])
    insert(2*root+2,value);
}
void preorder(int root){
    if(tree[root]==-1) return;
    printf("%d ", tree[root]);
    preorder(2*root+1);
    preorder(2*root+2);
}
void inorder(int root){
    if(tree[root] == -1) return;
    inorder(2*root+1);
    printf("%d ", tree[root]);
    inorder(2*root+2);
}
void postorder(int root){
    if(tree[root] == -1) return;
    postorder(2*root+1);
    postorder(2*root+2);
    printf("%d ", tree[root]);
}
int search(int i,int target) {
    while(i<SIZE && tree[i]!=-1){
        if(tree[i]==target)
        return i;
    else if(target<tree[i])
        i=2*i+1;
    else
        i=2*i+2;
    }
    return -1;
}
int findMin(int i){
    while(i*2+1<SIZE && tree[i*2+1]!=-1){
        i=2*i+1;
    }
    return i;
}
int findMax(int i){
    while(i*2+2<SIZE && tree[i*2+2]!=-1){
        i=2*i+2;
    }
    return i;
}
void delete(int i,int val){ //first search the element and replace the last element 
    i=search(i,val);
    if(i==-1)
    printf("Invalid Position!!\n");
else{
        int left=2*i+1;
        int right=2*i+2;
    if((left>=SIZE || tree[left]==-1) && (right>=SIZE || tree[right]==-1))
            tree[i]=-1;
    else if(right>=SIZE || tree[right]==-1){
        int max=findMax(left);
        tree[i]=tree[max];
        delete(max,tree[max]);
    }
    else if(left>=SIZE || tree[left]==-1){
        int min=findMin(right);
        tree[i]=tree[min];
        delete(min,tree[min]);
    }
    else {
        int min=findMin(right);
        tree[i]=tree[min];
        delete(min,tree[min]);
    }
}
}
int main(){
    int choice, n, val, res;
    initialize();
    while(1){
        printf("1. Insert elements\n");
        printf("2. Preorder traversal\n");
        printf("3. Inorder traversal\n");
        printf("4. Postorder traversal\n");
        printf("5. Search an element\n");
        printf("6. Delete an element\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            printf("Enter the number of values to insert: ");
            scanf("%d", &n);
            printf("Enter the values: ");
            for (int i = 0; i < n; i++) {
                int value;
                scanf("%d", &value);
                insert(0, value);
            }
            break;
            case 2:
                printf("Preorder traversal: ");
                preorder(0);
                printf("\n");
                break;
            case 3:
                printf("Inorder traversal: ");
                inorder(0);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postorder(0);
                printf("\n");
                break;
            case 5:
                printf("Enter the element to search: ");
                scanf("%d", &val);
                if ((search(0,val))!= -1)
                    printf("Element %d found in the tree\n", val);
                else
                    printf("Element %d not found in the tree\n", val);
                break;
            case 6:
                printf("Enter the element to delete: ");
                scanf("%d", &val);
                delete(0,val);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } 
}
