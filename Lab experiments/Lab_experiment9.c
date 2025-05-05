//Implement a Circular Linked List and develop functions to perform insertion, deletion and linear search operations
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}node;
node* head = NULL;
node* createnewnode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Empty node\n");
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertNodeinBeg(int value) {
    node* newNode = createnewnode(value);
    if (head == NULL) {
        head = newNode;
            head->next = head;
    } else {
        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void insertNodeatEnd(int value) {
    node* newNode = createnewnode(value);
    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void insertAtanyPos(int value, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    node* newNode = createnewnode(value);
    if (pos == 1) {
        insertNodeinBeg(value);
        return;
    }
    node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp->next == head) {
            printf("Position out of bounds\n");
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNodefromBeg() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    node* toDelete = head;
    head = head->next;
    temp->next = head;
    free(toDelete);
}

void deleteNodefromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    node* toDelete = temp->next;
    temp->next = head;
    free(toDelete);
}

void deleteNodefromanyPos(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        deleteNodefromBeg();
        return;
    }
    node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp->next == head) {
            printf("Position out of bounds\n");
            return;
        }
        temp = temp->next;
    }
    node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

void search(int target) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node* temp = head;
    int pos = 1;
    do {
        if (temp->data == target) {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Element not found\n");
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main(){
    while(1){
        printf("---- Circular Singly Linked list----\n");
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
