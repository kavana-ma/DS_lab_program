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

NODE delete_first(NODE first){
    NODE temp=first;
    if (first == NULL) {
        printf("Empty\n");
        return NULL;
    }
    first=first->next;
    free(temp);
    return first;
}

NODE delete_end(NODE first){
    if (first == NULL) {
        printf("Empty\n");
        return NULL;
    }
    NODE prev,last;
    prev=NULL;
    last=first;
    while(last->next!=NULL){
        prev=last;
        last=last->next;
    }
    prev->next=NULL;
    free(last);
    return first;
}

NODE delete_value(NODE first,int value){
    if (first == NULL) {
        printf("Empty\n");
        return NULL;
    }
    NODE prev,current;
    prev=NULL;
    current=first;
    while(value!=current->value || current->next!=NULL){
        prev=current;
        current=current->next;
    }
    if(current==NULL){
        printf("Value notfound");
        return first;
    }
    prev->next=current->next;
    free(current);
    return first;
}

NODE insert_beginning(NODE first, int item) {
    NODE new_node = get_node();
    new_node->value = item;
    new_node->next = first;
    return new_node;
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

    first = insert_beginning(first, 1);
    first = insert_beginning(first, 2);
    first = insert_beginning(first, 3);
    first = insert_beginning(first, 4);
    first = insert_beginning(first, 5);
    first = insert_beginning(first, 6);

    printf("List before deleting:\n");
    display(first);
    
    printf("Deleting at first.\n");
    first = delete_first(first);
    printf("List after deleting 1st: \n");
    display(first);

    printf("Deleting  at the end:\n");
    first = delete_end(first);
    printf("List after deleting at end: \n");
    display(first);

    printf("Deleting  value 2:\n");
    first = delete_value(first, 2);
    printf("List after deleting value 2: \n");
    display(first);

    return 0;
}
