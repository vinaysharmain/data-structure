//Implement a Stack using Linked List and develop functions to perform push and pop operations.
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*top=NULL;
void push(int value){
struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
if(temp==NULL)
printf("Stack Overflow");
else{
    temp->data=value;
    temp->next=top;
    top=temp;
    printf("Element %d push in the stack!!!\n", value);
}
}
int pop(){
    if(top==NULL){
        printf("Stack Underflow!!!\n");
        return -1;
    }
    else{
        struct Node *temp=top;
        top=top->next;
        int val=temp->data;
        free(temp);
        return val;
    }
}
int peek(){
    if(top==NULL){
        printf("Stack is empty!!!\n");
        return -1;
    }
    else return top->data;
}
void show(){
    if(top==NULL)
    printf("Stack is empty!!!\n");
    else{
        printf("Stack elements are: ");
        struct Node *temp=top;
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}
int main(){
        while(1){
            printf("1. Push\n");
            printf("2. Pop\n");
            printf("3. Peek\n");
            printf("4. Show\n");
            printf("5. Exit\n");
            int choice,val,res;
            printf("Enter choice: ");
            scanf("%d", &choice);
            switch(choice){
                case 1: printf("Enter value: ");
                        scanf("%d", &val);
                        push(val);
                break;
                case 2: res=pop();
                        if(res!=-1)
                            printf("%d pop from the stack!!\n", res);
                break;
                case 3: res=peek();
                        if(res != -1)
                        printf("Stack top element is %d\n", res);
                break;
                case 4: show();
                break;
                case 5: exit(0);
                default:
                printf("Invalid choice!!!\n");
            }
        }
        return 0;
    }
