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

NODE concatenate(NODE first1, NODE first2){
    if(first1 == NULL && first2==NULL){ return NULL;}
    if(first1==NULL){ return first2; }
    if(first2==NULL){ return first1; }
    NODE temp=first1;
    while(temp->next!= NULL){
        temp=temp->next;
    }
    temp->next=first2;
    return first1;
}

NODE reverse(NODE first){
    if(first==NULL){
        return NULL;
    }
    NODE curr=NULL,temp;
    while(first!=NULL){
        temp=first;
        first=first->next;
        temp->next=curr;
        curr=temp;
    }
    return curr;
}

void sort(NODE first){
    NODE temp1=first,temp2=first->next;
    while((temp1->next)!=NULL){
        while(temp2!=NULL){
            if(temp1->value >= temp2->value){
                int x=temp1->value;
                temp1->value=temp2->value;
                temp2->value=x;
            }
        temp2=temp2->next;
        }
    temp1=temp1->next;
    }
}

int main() {
    int choice, item;
    NODE first1 = NULL, first2 = NULL, mergedList = NULL;
    NODE ConcatenatedList;

    // Menu to choose operations
    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Insert item into first list\n");
        printf("2. Insert item into second list\n");
        printf("3. Display first list\n");
        printf("4. Display second list\n");
        printf("5. Concatenate lists\n");
        printf("6. Reverse the first list\n");
        printf("7. Sort the first list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to insert into first list: ");
                scanf("%d", &item);
                first1 = insert_beginning(first1, item);
                break;
            case 2:
                printf("Enter item to insert into second list: ");
                scanf("%d", &item);
                first2 = insert_beginning(first2, item);
                break;
            case 3:
                printf("First list: ");
                display(first1);
                break;
            case 4:
                printf("Second list: ");
                display(first2);
                break;
            case 5:
                ConcatenatedList = concatenate(first1, first2);
                printf(" Concatenated List: ");
                display( ConcatenatedList);
                break;
            case 6:
                first1 = reverse(first1);
                printf("First list after reversal: ");
                display(first1);
                break;
            case 7:
                sort(first1);
                printf("First list after sorting: ");
                display(first1);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice..\n");
        }
    }

    return 0;
}
