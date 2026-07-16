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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        if (list1->val > list2->val)
            swap(list1, list2);

        ListNode* curr = list1;
        ListNode* next = NULL;

        while (list2) {
            if (curr->next == NULL) {
                curr->next = list2;
                break;
            }
            if (list2->val >= curr->val && curr->next->val >= list2->val) {
                next = list2->next;
                list2->next = curr->next;
                curr->next = list2;
                curr = curr->next;
                list2 = next;
            } else
                curr = curr->next;
        }

        return list1;
    }
};