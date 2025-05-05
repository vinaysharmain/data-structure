#include <stdio.h> 
#include <stdlib.h>
#define SIZE 100
typedef struct PriorityQueue{
    int element;
    int priority;
} pqueue;
pqueue pq[SIZE];
int front=-1,rear=-1,i;
int isEmpty(){
    return (front==-1)? 1:0;
}
int isFull(){
    return (rear==SIZE-1)? 1:0;
}
void Enqueue(int data,int priority){
    if(isEmpty()){
        rear=rear+1;
        pq[rear].element=data;
        pq[rear].priority=priority;
        front=rear;
    }
    else{
        for(i=front;i<=rear;i++){
            if(pq[i].priority<priority){
                for(int j=rear;j>=i;j--){
                    pq[j+1].element=pq[j].element;
                    pq[j+1].priority=pq[j].priority;
                }
                pq[i].element=data;
                pq[i].priority=priority;
                rear++;
                break;
            }
        }
        if(i==(rear+1)){
            rear=rear+1;
            pq[rear].element=data;
            pq[rear].priority=priority;
        }
    }
    printf("Element Inserted!!!\n");
}
int Dequeue(){
    int data=pq[front].element;
    if(front==rear) front=rear=-1;
    else front++;
    return data;
}
int peek(){
    return pq[front].element;
}
void display(){
    for(int i=front;i<=rear;i++){
        printf("Element: %d => Priority: %d\n", pq[i].element, pq[i].priority);
    }
    printf("\n");
}
int main(){
    while(1){
        printf("----Priority Queue----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        int choice,data,p;
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: if(isFull()) printf("Queue Overflow!!!\n");
            else{ 
                printf("Enter element: ");
                scanf("%d", &data);
                printf("Enter Priority: ");
                scanf("%d", &p);
                Enqueue(data,p);
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
