//Implement a Queue using Linked List and develop functions to perform enqueue and dequeue operations.
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;
void Enqueue(int value) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Queue Overflow\n");
        return;
    }
    else{
    temp->data = value;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
    printf("%d inserted in queue\n", value);
    }
}
}
int Dequeue() {
    if (front == NULL) {
        printf("Queue is empty!!\n");
    }
else {
    struct Node *temp = front;
    front = front->next;
    if (front == NULL) 
        rear = NULL;
    int data = temp->data;
    free(temp);
    return data;
}
}
int peek() {
    if (front == NULL) {
        printf("Queue is empty!!\n");
        return -1;
    }
    return front->data;
}

void show() {
    if (front == NULL) {
        printf("Queue is empty!!\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Show\n");
        printf("5. Exit\n");
        int choice,val,res;
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter value: ");
                    scanf("%d", &val);
                    Enqueue(val);
            break;
            case 2: res=Dequeue();
                    if(res!=-1)
                        printf("%d dequeue from the queue!!\n", res);
            break;
            case 3: res=peek();
                    if(res != -1)
                    printf("Queue top element is %d\n", res);
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
