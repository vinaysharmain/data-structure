//Implement a Doubly Linked List and develop functions to perform insertion, deletion and linear search operations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void insertNodeinBeg(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

void insertNodeatEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtanyPos(int value, int pos) {
    if(head==NULL)
    printf("List is empty!!!\n");
    else if (pos == 1) {
        insertNodeinBeg(value);
    }
    else{
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* temp=head;
    int i=1;
    while(i!=pos && temp!=NULL){
        i++;
        temp=temp->next;
    }
    if(temp!=NULL){
        newNode->prev=temp->prev;
        temp->prev->next=newNode;
        newNode->next=temp;
        temp->prev=newNode;
    }
    else
    printf("Invalid Position!!!\n");
    }
}

void deleteNodefromBeg() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

void deleteNodefromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
}

void deleteNodefromanyPos(int pos) {
    if (pos == 1) {
        deleteNodefromBeg();
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void search(int target) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == target) {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element not found\n");
}

void display() {
    Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    while(1){
        printf("----Singly Linked list----\n");
        printf("1. Insert in beginning\n");
        printf("2. Insert Node at end\n");
        printf("3. Insert Node at any position\n");
        printf("4. Delete Node from Beginning\n");
        printf("5. Delete Node from end\n");
        printf("6. Delete Node from any position\n");
        printf("7. Search element in list\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        int choice,value,pos,target;
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter value: ");
                    scanf("%d", &value);
                    insertNodeinBeg(value);
             break;
            case 2: printf("Enter value: ");
                scanf("%d", &value);
                insertNodeatEnd(value);
            break;
            case 3: printf("Enter value: ");
                    scanf("%d", &value);
                    printf("Enter position: ");
                    scanf("%d", &pos);
                    insertAtanyPos(value,pos);
            break;
            case 4: deleteNodefromBeg(); break;
            case 5: deleteNodefromEnd(); break;
            case 6: printf("Enter position : ");
                    scanf("%d", &pos);
                    deleteNodefromanyPos(pos); break;
            case 7: printf("Enter target: ");
                    scanf("%d", &target);
                    search(target);
                    break;
            case 8: display(); break;
            case 9: return 0;
            default: printf("Invalid choice");
        }
    }
    return 0;
}
