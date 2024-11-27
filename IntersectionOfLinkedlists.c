typedef struct ListNode *NODE;

int getLength(NODE first) {
    int count = 0;
    while (first != NULL) {
        count++;
        first = first->next;
    }
    return count;
}

struct ListNode *getIntersectionNode(struct ListNode *A, struct ListNode *B) {
    int lenA = getLength(A);
    int lenB = getLength(B);

    while (lenA > lenB) {
        A = A->next;
        lenA--;
    }

    while (lenB > lenA) {
        B = B->next;
        lenB--;
    }

    while (A != NULL && B != NULL) {
        if (A == B) {
            return A;  
        }
        A = A->next;
        B = B->next;
    }

    return NULL;
}
