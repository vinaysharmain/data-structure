/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 int countnodes(struct ListNode* head){
    int count=0,i;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
 }
struct ListNode* deleteMiddle(struct ListNode* head) {
    int size=countnodes(head);
    int middle=size/2;
    if(middle==0) return NULL;
    else{
    struct ListNode *temp=head;
    int i=1;
    while(i<middle && temp->next!=NULL){
        i++;
        temp=temp->next;
    }
    if(temp->next!=NULL){
        struct ListNode *t=temp->next;
        temp->next=temp->next->next;
        free(t);
    }
    return head;
}
}
