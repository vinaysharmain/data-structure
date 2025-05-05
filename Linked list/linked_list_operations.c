//Implement a Singly Linked List and develop functions to perform insertion, deletion and linear search operations.
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}node;
node *head=NULL;
node *createnode(int element){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=element;
    newnode->next=NULL;
    return newnode;
}
void insertNodeinBeg(int element){
    node *newnode=createnode(element);
    newnode->next=head;
    head=newnode;
    printf("Node Inserted!!!\n");
}
void insertNodeatEnd(int element){
    node *newnode=createnode(element);
    if(head==NULL) head=newnode;
    else{
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        printf("Node inserted!!\n");
    }
}
void insertAtanyPos(int element,int pos){
    if(head==NULL) 
    printf("List is empty!!!\n");
    else if(pos==1) insertNodeinBeg(element);
    else{
        node *temp=head;
        int i=1;
        while(i<pos-1 && temp->next!='\0'){
            temp=temp->next;
            i++;
        }
        if(temp->next!=NULL && i>1){
            node *newnode=createnode(element);
            newnode->next=temp->next;
            temp->next=newnode;
            printf("Node inserted!!!\n");
        }
        else{
            printf("Invalid position!!!\n");
        }
    }
}
void deleteNodefromBeg(){
    if(head==NULL)
    printf("Empty List!!!\n");
    else{
        node*temp=head; //to deallocate memory pass it to pointer
        head=head->next;
        free(temp); //delete the memory
        printf("Node deleted!!!\n");
    }
}
void deleteNodefromEnd(){
    if(head==NULL)
    printf("List is empty!!!\n");
    else{
        node *t;
        if(head->next==NULL){
            t=head;
            head=NULL;
    }
    else{
        node *temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        t=temp->next;
        temp->next=NULL;
    }
        free(t);
        printf("Node Deleted!!!\n");
    }
}
void deleteNodefromanyPos(int pos){
    if(head == NULL) 
        printf("List is empty!!!\n");
    else if(pos == 1) 
        deleteNodefromBeg();
    else{
        node *temp=head;
        int i=1;
        while(i<pos-1 && temp->next!=NULL){
            i++;
            temp=temp->next;
        }
        if(temp->next!=NULL && pos>0){
            node *t=temp->next;
            temp->next=temp->next->next;
            free(t);
            printf("Node deleted!!!\n");
        }
        else
        printf("Invalid position!!!\n");
    }
}
void search(int target){
    if(head==NULL)
    printf("Empty list!!!\n");
    else{
        node *temp=head;
        while(temp!=NULL){
            if(temp->data==target){
                printf("Found!!!\n");
                return;
            }
            temp=temp->next;
        }
}
}
void sort(){
    node *last=NULL;
    for(node *i=head ; i->next!=NULL ; i=i->next){
        node *j;
        for(j=head ; j->next!=last ; j=j->next){
            if(j->data > j->next->data){
                int temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
        last=j;
    }
    printf("Sorting completed!!!");
}
void display(){
    if(head==NULL) 
    printf("Empty list!!\n");
    else{
        node *temp=head;
        while(temp!='\0'){
            printf("%d ", temp->data);
            temp=temp->next;
        }
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
        printf("8. Sorting of element\n");
        printf("9. Display List\n");
        printf("10. Exit\n");
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
            case 8: sort(); break;
            case 9: display(); break;
            case 10: return 0;
            default: printf("Invalid choice");
        }
    }
    return 0;
}
