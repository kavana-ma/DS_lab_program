#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};
typedef struct node *NODE;

NODE get_node() {
    NODE ptr = (NODE)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory not allocated\n");
    }
    return ptr;
}

NODE insert_beginning(NODE first, int item) {
    NODE new_node = get_node();
    new_node->value = item;
    new_node->next = first;
    return new_node;
}

NODE insert_end(NODE first, int item) {
    NODE new_node = get_node();
    new_node->value = item;
    new_node->next = NULL;
    if (first == NULL) {
        return new_node;
    }
    NODE temp = first;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return first;
}

NODE insert_pos(NODE first, int item, int pos) {
    NODE new_node = get_node();
    new_node->value = item;
    if (pos == 1) {
        new_node->next = first;
        return new_node;
    }
    int count = 1;
    NODE prev = NULL, current = first;
    while (count < pos && current != NULL) {
        prev = current;
        current = current->next;
        count++;
    }
    if (prev != NULL) {
        prev->next = new_node;
        new_node->next = current;
    } else {
        printf("Invalid position\n");
    }
    return first;
}

void display(NODE first) {
    NODE temp = first;
    if (first == NULL) {
        printf("Empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int item, pos, choice;
    NODE first = NULL;

    while (1) {
        printf("Choose an operation:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to insert at beginning: ");
                scanf("%d", &item);
                first = insert_beginning(first, item);
                break;
            case 2:
                printf("Enter item to insert at end: ");
                scanf("%d", &item);
                first = insert_end(first, item);
                break;
            case 3:
                printf("Enter item to insert and position: ");
                scanf("%d %d", &item, &pos);
                first = insert_pos(first, item, pos);
                break;
            case 4:
                printf("List: ");
                display(first);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
