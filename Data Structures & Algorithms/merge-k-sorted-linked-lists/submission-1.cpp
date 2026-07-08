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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         if (lists.empty()) return nullptr;
        int k = lists.size();
         //using divide and conquer rule to reduce time complexity to ologn
           while (k > 1) {
            for (int i = 0; i < k / 2; i++) {
                lists[i] = mergetwoList(lists[i], lists[k - 1 - i]);
            }
            k = (k + 1) / 2; // Move the boundary for the next merge step
        }
        return lists[0];
    }
    ListNode* mergetwoList(ListNode* list1,ListNode* list2){
        ListNode dummy;
        ListNode* head = &dummy;
        while(list1 != nullptr && list2 != nullptr){
            int first = list1->val;
            int second = list2->val;
            if(first < second){
               head->next = list1;
               list1 = list1->next;
            }else{
               head->next = list2;
               list2 = list2->next;
            }
            head = head->next;
        }
        if(list1 != nullptr){
            head->next = list1;
        }else{
            head->next = list2;
        }
        return dummy.next;
    }
};
