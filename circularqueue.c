#include <stdio.h>
#include <stdlib.h>
#define QSIZE 5

void insert_rear(int q[], int *rear, int *front, int *count, int item) {
    if (*count == QSIZE) {
        printf("Queue Overflow\n");
        return; 
    }
    *rear = (*rear + 1) % QSIZE; 
    q[*rear] = item;
    (*count)++;
}

int delete_front(int *rear, int *front, int *count, int q[]) {
    if (*count == 0) {
        printf("Queue Underflow\n");
        return -1; 
    }
    int item_deleted = q[*front];
    *front = (*front + 1) % QSIZE; 
    (*count)--;
    return item_deleted; 
}

void display(int q[], int front, int count) {
    if (count == 0) {
        printf("Queue is empty\n");
        return; 
    for (int i = 0; i < count; i++) { 
        printf("%d ", q[(front + i) % QSIZE]); 
    }
    printf("\n");
}
}
int main() {
    int front = 0, rear = -1, count = 0, q[QSIZE], del, item, choice;
    while (1) {
        printf("Enter choice:\n 1) Insert 2) Delete 3) Display 4) Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                printf("Enter item to insert: ");
                scanf("%d", &item);
                insert_rear(q, &rear, &front, &count, item);
                break;
            }
            case 2: {
                del = delete_front(&rear, &front, &count, q);
                if (del != -1) {
                    printf("Item deleted: %d\n", del);
                }
                break;
            }
            case 3: {
                display(q, front, count);
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    }
    return 0; 
}
