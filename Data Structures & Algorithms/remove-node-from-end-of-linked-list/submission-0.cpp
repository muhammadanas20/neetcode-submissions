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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move fast pointer n steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        // Move both until fast hits the end
        while (fast != nullptr) {   
            fast = fast->next;
            slow = slow->next;
        }
        
        // Delete target node
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};