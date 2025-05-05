//Implement a Queue using Array and develop functions to perform enqueue and dequeue operations.
#include <stdio.h> 
#include <stdlib.h>
#define SIZE 100
int queue[SIZE], front =-1, rear=-1;
int isEmpty(){
    return (front==-1)? 1:0;
}
int isFull(){
    return (rear==SIZE-1)? 1:0;
}
void Enqueue(int data){
    queue[++rear]=data;
    if(front==-1) front=rear;
    printf("Element Inserted!!!\n");
}
int Dequeue(){
    int data=queue[front];
    if(front==rear) front=rear=-1;
    else front++;
    return data;
}
int peek(){
    return queue[front];
}
void display(){
    for(int i=front;i<=rear;i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main(){
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        int choice,data;
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: if(isFull()) printf("Queue Overflow!!!\n");
            else{ 
                printf("Enter element: ");
                scanf("%d", &data);
                Enqueue(data);
            }
            break;
            case 2: if(isEmpty()) printf("Queue Underflow!!!\n");
            else printf("%d is dequeue from the queue\n", Dequeue());
            break;
            case 3: if(isEmpty()) printf("Queue Empty!!!\n");
            else printf("Element available in front of queue is %d\n", peek()); 
            break;
            case 4: if(isEmpty()) printf("Queue Empty!!!\n");
            else display();
            break;
            case 5: return 0; break;
            default: printf("Invalid Choice!!!\n");
        }
    }
    printf("\n");
}
