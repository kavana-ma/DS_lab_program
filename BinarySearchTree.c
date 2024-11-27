#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *left, *right;
};
typedef struct Node *NODE;


NODE newNode(int key) {
    NODE node = (NODE)malloc(sizeof(struct Node));
    node->value = key;
    node->left = node->right = NULL;
    return node;
}

NODE insert(NODE root, int key) {
    if (root == NULL) {
        return newNode(key);
    }

    if (key < root->value) {
        root->left = insert(root->left, key);
    } else if (key > root->value) {
        root->right = insert(root->right, key);
    }

    return root;
}

void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

void preorder(NODE root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
}

int main() {
    NODE root = NULL;
    int choice, value;

    do {
        printf("\nBST Operations\n");
        printf("1. Insert a node\n");
        printf("2. Display: In-order\n");
        printf("3. Display: Pre-order\n");
        printf("4. Display: Post-order\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Value inserted:%d\n",value);
                break;
            case 2:
                if (root == NULL) {
                    printf("The tree is empty!\n");
                } else {
                    inorder(root);
                }
                break;
            case 3:
                if (root == NULL) {
                    printf("The tree is empty!\n");
                } else {
                    preorder(root);
                }
                break;
            case 4:
                if (root == NULL) {
                    printf("The tree is empty!\n");
                } else {
                    postorder(root);
                }
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
