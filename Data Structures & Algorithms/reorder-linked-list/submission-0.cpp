/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


vector<ListNode*> splitter(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* head2 = slow->next;
    slow->next = NULL;
    ListNode* head1 = head;

    return {head1, head2};
}

ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> heads = splitter(head);
        ListNode* head1 = heads[0];
        ListNode* head2 = heads[1];
        head2 = reverse(head2);

        ListNode* next1 = NULL;
        ListNode* next2 = NULL;
        while(head1 && head2) {
            next1 = head1->next;
            next2 = head2->next;
            head2->next = head1->next;
            head1->next = head2;
            head1 = next1;
            head2 = next2;
        }
    }
};