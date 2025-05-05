//Implement a Binary Search Tree using Linked List and develop functions to perform traversal, searching, insertion and deletion operations.    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct TreeNode{
    struct TreeNode* left;
    int data;
    struct TreeNode* right;
}tnode;
tnode* createNode(int element){
    tnode* node=(tnode*)malloc(sizeof(tnode));
    node->data=element;
    node->left=node->right=NULL;
    return node;
}
tnode* insert(tnode* root,int value){
if(root==NULL)
return createNode(value);
else if(value<root->data)
root->left=insert(root->left,value);
else if(value>root->data)
root->right=insert(root->right,value);
return root;
}
void preorder(tnode* root){
    if(root==NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(tnode* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ", root->data); 
    inorder(root->right);
}
void postorder(tnode* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
tnode* search(tnode* root,int target){
    if (root == NULL)
        return NULL;
    else if (target == root->data)
        return root;
    else if (target < root->data)
        return search(root->left, target);
    else
        return search(root->right, target);
}
tnode* findMin(tnode* root) {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left; // Move to the leftmost node
    }
    return root; // This is the node with the minimum value
}
tnode * delete(tnode* root,int value){
    if(root==NULL) return NULL;
    else if(value<root->data)
    root->left=delete(root->left,value);
    else if(value>root->data)
    root->right=delete(root->right,value);
    else{//when element found
        if(root->left==NULL && root->right==NULL){//Zero child
            free(root);
            return NULL;
        }
        else if(root->right==NULL){//left child only
            tnode* temp=root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL){//right child only
            tnode* temp=root->right;
            free(root);
            return temp;
        }
        else{//two child(left and right)
            tnode* temp=findMin(root->right);
            root->data=temp->data;
            delete(root->right,temp->data);
        }
    }
    return root;
}
int main(){
    int choice,val,n;
    tnode* root=NULL;
    while(1){
        printf("1. Insert\n");
        printf("2. Pre-order\n");
        printf("3. In-order\n");
        printf("4. Post-order\n");
        printf("5. Search\n");
        printf("6. Delete\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            printf("Enter the number of values to insert: ");
            scanf("%d", &n);
            printf("Enter the values: ");
            for (int i = 0; i < n; i++) {
                int value;
                scanf("%d", &value);
                root = insert(root, value);
            }
            break;
            case 2:
                printf("Pre-order traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("In-order traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search(root, val))
                    printf("Value %d found in the tree.\n", val);
                else
                    printf("Value %d not found in the tree.\n", val);
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                delete(root, val);
                printf("Value %d deleted from the tree.\n", val);
                break;
            case 7:
                exit(0);
                break;
            default:
            printf("Invalid choice!!!\n");
        }
    }
}
