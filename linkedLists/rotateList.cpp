#include <iostream>

using namespace std;

/*
 * - Problem:
 * Rotate list
 *
 * - Problem description:
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 */

// singly-linked list node definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int getListSize(ListNode* node) {
    int count = 0;

    while (node != NULL) {
        count++;
        node = node->next;
    }

    return count;
}

ListNode* rotateList(ListNode* head, int k) {
    int N = getListSize(head);
    if (k == 0 || N == 0) return head;
    k = k % N;

    // link the old tail with the old head
    ListNode* oldTail = head;
    for (int i = 0; i < N - 1; i++) {
        oldTail = oldTail->next;
    }
    oldTail->next = head;

    // split the list and fix pointers
    ListNode* newHead = head;
    ListNode* newTail = NULL;
    for (int i = 0; i < N - k; i++) {
        newTail = newHead;
        newHead = newHead->next;
    }
    newTail->next = NULL;

    return newHead;
}

void rotateListTester() {
    ListNode* A = new ListNode(1);
    ListNode* B = new ListNode(2);
    ListNode* C = new ListNode(3);
    ListNode* D = new ListNode(4);
    ListNode* E = new ListNode(5);
    ListNode* F = new ListNode(6);

    A->next = B;
    B->next = C;
    C->next = D;
    D->next = E;
    E->next = F;

    rotateList(A, 2);
}
