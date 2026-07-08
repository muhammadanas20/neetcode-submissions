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
    void reorderList(ListNode* head) {
        // using fast and slow pointer find mid and last the merge them
        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        //reverse right half
        ListNode* y = slow->next;
        slow->next = nullptr; // its where two list splits slownext is tail of first list
        ListNode* prev = nullptr;
        while(y != nullptr){
           ListNode* temp = y->next;
           y->next = prev;
           prev = y;
           y = temp;
        }
        ListNode *x = head;
        y = prev; //second list
        while(y != nullptr){  //y is in condition cuz is shorter or equal
            ListNode* temp = x->next;
            ListNode* temp2 = y->next;
            x->next = y;
            y->next = temp;
            x = temp;
            y = temp2;
        }
    }
};
