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
    int item;
    NODE first = NULL;
    printf("Creating linked list:\n");
    first = insert_beginning(first, 1);
    first = insert_beginning(first, 2);
    first = insert_beginning(first, 3);

    printf("List after creating: ");
    display(first);

    printf("Inserting 10 at the beginning:\n");
    first = insert_beginning(first, 10);
    display(first);

    printf("Inserting 4 at the end:\n");
    first = insert_end(first, 4);
    display(first);

    printf("Inserting 5 at position 2:\n");
    first = insert_pos(first, 5, 2);
    display(first);

    return 0;
}
