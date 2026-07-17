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

ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;

    while(curr!=nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverse(head);
        int count = 1;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(count < n) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        if (prev == nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        } else {
            prev->next = curr->next;
            delete curr;
        }

        return reverse(head);
    }
};