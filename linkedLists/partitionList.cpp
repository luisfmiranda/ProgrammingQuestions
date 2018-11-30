#include <iostream>

using namespace std;

/*
 * - Problem:
 * Partition list
 *
 * - Problem description:
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or
 * equal to x. You should preserve the original relative order of the nodes in each of the two partitions.
 */

// singly-linked list node definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* A, int B) {
    if (A == NULL) return NULL; // empty list
    if (A->next == NULL) return A; // only one element on the list

    // iterators
    ListNode* prev = NULL;
    ListNode* curr = A;

    // head and tail of the list with elements >= B
    ListNode* newListHead = new ListNode(0);
    ListNode* newListTail = newListHead;

    // iterate through the list
    while (curr != NULL) {
        if (curr->val >= B) {
            // insert the current node in the newly created list
            if (newListTail == NULL) {
                newListTail = curr;
            } else {
                newListTail->next = curr;
                newListTail = newListTail->next;
            }

            // update the original list
            if (prev != NULL) {
                prev->next = curr->next;
            } else {
                A = A->next;
            }

            // "close" the end of the newly created list
            curr->next = NULL;

            // update the iterator (prev should keep its position)
            if (prev != NULL) {
                curr = prev->next;
            } else {
                curr = A;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    // merge the lists
    if (prev != NULL) {
        prev->next = newListHead->next;
    } else {
        A = newListHead->next;
    }

    return A;
}

void partitionTester() {
    ListNode* A = new ListNode(841);
    ListNode* B = new ListNode(38);
    ListNode* C = new ListNode(418);
    ListNode* D = new ListNode(55);
    ListNode* E = new ListNode(133);
    ListNode* F = new ListNode(185);

    A->next = B;
    B->next = C;
    C->next = D;
    D->next = E;
    E->next = F;

    partition(A, 62);
}
