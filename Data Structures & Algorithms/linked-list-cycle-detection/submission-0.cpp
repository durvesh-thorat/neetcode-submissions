/**
 * Definition for singly-linked list.
  * struct ListNode {
   *     int val;
    *     ListNode *next;
     *     ListNode(int x) : val(x), next(NULL) {}
      * };
       */
       class Solution {
       public:
           bool hasCycle(ListNode *head) {
                                           if (head == nullptr) return false;
                                           ListNode *slow = head;
                                                   ListNode *fast = head;
                                                          
                                                                  // The loop condition alone safely handles empty or 1-node lists
                                                                          while (fast && fast->next) {
                                                                                      slow = slow->next;
                                                                                                  fast = fast->next->next;
                                                                                                             
                                                                                                                         if (slow == fast) return true;
                                                                                                                                 }
                                                                                                                                        
                                                                                                                                                return false;
                                                                                                                                                    }
                                                                                                                                                    };