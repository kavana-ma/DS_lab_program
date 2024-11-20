#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
};
typedef struct Node* NODE;

NODE get_node() {
    NODE ptr = (NODE)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory not allocated\n");
    }
    return ptr;
}

NODE insert_beginning(NODE first, int item) {
    NODE new_node = get_node();
    new_node->value = item;
    new_node->next = first;
    new_node->prev = NULL;
    if (first != NULL) {
        first->prev = new_node;
    }
    return new_node;
}

NODE insert_left_value(NODE first, int item, int key) {
    NODE curr = first;
    NODE new_node = get_node();
    new_node->value = item;

     if (curr == NULL) {
        printf("value not found.\n");
        return first;
    }

    while (curr != NULL && curr->value != key) {
        curr = curr->next;
    }

    new_node->next = curr;
    new_node->prev = curr->prev;
    (curr->prev)->next = new_node;
    curr->prev = new_node;
}

NODE deleteNode(NODE first, int value) {
    NODE curr = first;
    if (curr == NULL) {
        printf("Value %d not found.\n", value);
        return first;
    }
    
    while (curr != NULL && curr->value != value) {
        curr = curr->next;
    }
    (curr->prev)->next = curr->next;
    (curr->next)->prev = curr->prev;
    free(curr);
    return first;
}

void displayList(NODE first) {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    NODE curr = first;
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    NODE first = NULL;
    int choice, value, key;

    do {
        printf("Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert to the left \n");
        printf("3. Delete a node by value\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at beginning: ");
                scanf("%d", &value);
                first = insert_beginning(first, value);
                break;

            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the key value: ");
                scanf("%d", &key);
                insert_left_value(first, value, key);
                break;

            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                first = deleteNode(first, value);
                break;

            case 4:
                printf("List : ");
                displayList(first);
                break;

            case 5:
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
