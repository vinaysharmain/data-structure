//Implement a a list using array and develop functions to perform insertion, deletion and linear search operations.
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void insert(int *list, int *size) {
    int pos, value, i;
    printf("Enter Position: ");
    scanf("%d", &pos);
    printf("Enter Value: ");
    scanf("%d", &value);
    pos--;
    if (pos < 0 || pos > *size) {
        printf("Invalid Position!\n");
        return;
    }
    for (i = *size; i > pos; i--)
        list[i] = list[i - 1];
    list[pos] = value;
    (*size)++;
}

void delete(int *list, int *size) {
    int pos, i;
    printf("Enter Position: ");
    scanf("%d", &pos);
    pos--;
    if (pos < 0 || pos >= *size) {
        printf("Invalid Position!\n");
        return;
    }
    for (i = pos; i < *size - 1; i++)
        list[i] = list[i + 1];
    (*size)--;
}

void search(int *list, int size) {
    int val, i;
    printf("Enter Searching Element: ");
    scanf("%d", &val);
    for (i = 0; i < size; i++) {
        if (val == list[i]) {
            printf("Element found at index %d\n", i);
            return;
        }
    }
    printf("Element not found!\n");
}
void display(int *list, int size){
    for (int i=0; i < size; i++){
        printf("%d ",list[i]);
    }
    printf("\n\n");
}

int main() {
    int list[MAX_SIZE], size, i;
    printf("Enter List Size: ");
    scanf("%d", &size);
    printf("Enter Elements In List: ");
    for (i = 0; i < size; i++)
        scanf("%d", &list[i]);
    printf("\n");
    printf("Insertion in list\n");
    insert(list, &size);
    printf("After insertion, list elements: "); display(list, size);
    printf("Deletion in list\n");
    delete(list, &size);
    printf("After deletion, list elements: "); display(list, size);
    printf("Searching in List\n");
    search(list, size);
    return 0;
}
