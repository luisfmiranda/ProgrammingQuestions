#include <iostream>

using namespace std;

/*
 * - Problem:
 * Merge two sorted lists
 *
 * - Problem description:
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes
 * of the first two lists, and should also be sorted.
 */

// singly-linked list node definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
    if (A == NULL) return B;
    if (B == NULL) return A;

    ListNode* mergedListHead = NULL;

    // find out which node will be the head of the merged list
    if (A->val < B->val) {
        mergedListHead = A;
        A = A->next;
    } else {
        mergedListHead = B;
        B = B->next;
    }

    ListNode* mergedListTail = mergedListHead;

    // go through the list, adding the smallest node of each to the merged list
    while (A != NULL && B != NULL) {
        if (A->val < B->val) {
            mergedListTail->next = A;
            A = A->next;
        } else {
            mergedListTail->next = B;
            B = B->next;
        }

        mergedListTail = mergedListTail->next;
    }

    // add the rest of the nodes to the merged list
    if (A != NULL) {
        mergedListTail->next = A;
    } else {
        mergedListTail->next = B;
    }

    return mergedListHead;
}
