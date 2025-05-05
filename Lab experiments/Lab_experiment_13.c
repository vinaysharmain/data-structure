//Implement a Binary Tree using Array and develop functions to perform traversal, searching, insertion and deletion operations.
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int tree[SIZE];
int size=0;
void initialize(){
    for(int i=0;i<SIZE;i++)
        tree[i]=-1;
}
void insert(int n){
    printf("Enter the values: ");
    for(int i=size;i<n;i++){
        scanf("%d", &tree[size++]);
    }
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
// void search(int target,int root) {
//         if (tree[root] == -1) return 0; 
//         if (tree[root] == target){
//             printf("Element %d not found in the tree\n", target);
//             return 1;
//         }
//         return search(target,2*root+1)|| search(target,2*root+2);
//     }
int search(int target,int root) {
    for(int i=0;i<size;i++){
        if(tree[i]==target) return i;
    }
    return -1;
}
void delete(int val,int root){//first search the element and replace the last element 
    int i=search(val,0);
    if(i!=-1){
        tree[i]=tree[size-1];
        tree[size-1]=-1;
        size--;
        printf("Element Deleted!!!\n");
    }
    else{
        printf("Element not found!!!\n");
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
                printf("Enter the number of elements to insert: ");
                scanf("%d", &n);
                insert(n);
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
                if ((search(val, 0))!= -1)
                    printf("Element %d found in the tree\n", val);
                else
                    printf("Element %d not found in the tree\n", val);
                break;
            case 6:
                printf("Enter the element to delete: ");
                scanf("%d", &val);
                delete(val, 0);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } 
}
