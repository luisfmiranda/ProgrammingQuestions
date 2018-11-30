#include <iostream>

using namespace std;

/*
 * - Problem:
 * List cycle
 *
 * - Problem description:
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 */

// singly-linked list node definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode* head) {
    if (head == NULL || head->next == NULL) return NULL;

    ListNode* turtle = head; // moves one node at a time
    ListNode* hare = head; // moves two nodes at a time

    bool hasACycle = false;

    // if the hare meets the turtle again, then there is a cycle in the list
    while (turtle!= NULL && hare != NULL) {
        if (hare->next == NULL) return NULL;

        turtle = turtle->next;
        hare = hare->next->next;

        if (hare == turtle) {
            hasACycle = true;
            break;
        }
    }

    if (!hasACycle) return NULL;

    ListNode* newTurtle = head; // also moves one node at a time

    /*
     * This is a trick part. The distance from the meeting point to the beggining of the cycle is the same as the
     * distance from the head of the list to the beginning of the cycle. Thus, to find where the cycle starts we just
     * need to put another turtle in the head of the list and move the two turtles together. They will meet at the
     * beginning of the cycle.
     */
    while (newTurtle != turtle) {
        turtle = turtle->next;
        newTurtle = newTurtle->next;
    }

    return turtle;
}

void detectCycleTester() {
    ListNode* A = new ListNode(1);
    ListNode* B = new ListNode(2);
    ListNode* C = new ListNode(3);
    ListNode* D = new ListNode(4);
    ListNode* E = new ListNode(5);
    ListNode* F = new ListNode(6);
    ListNode* G = new ListNode(7);
    ListNode* H = new ListNode(8);

    A->next = B;
    B->next = C;
    C->next = D;
    D->next = E;
    E->next = F;
    F->next = G;
    G->next = H;
    H->next = D;

    detectCycle(A);
}