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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // If the list is empty OR only one node needs to be reversed,
        // there is nothing to do.
        if (!head || left == right)
            return head;

        // -------------------------------------------------------
        // Dummy Node
        // -------------------------------------------------------
        // Creates a fake node before the head.
        // This avoids special handling when left == 1.
        //
        // Example:
        // dummy -> 1 -> 2 -> 3 -> 4 -> 5
        //
        ListNode dummy(0);
        dummy.next = head;

        // prev should stop ONE NODE BEFORE the reversal starts.
        ListNode* prev = &dummy;

        // -------------------------------------------------------
        // Move prev to (left-1)th node.
        //
        // Example:
        // left = 2
        //
        // dummy -> 1 -> 2 -> 3 -> 4 -> 5
        //          ^
        //         prev
        //
        // If left = 1,
        // prev stays on dummy.
        // -------------------------------------------------------
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // curr is the FIRST node of the part that will be reversed.
        //
        // Example:
        // 1 -> 2 -> 3 -> 4 -> 5
        //      ^
        //     curr
        //
        ListNode* curr = prev->next;

        // -------------------------------------------------------
        // Reverse using Head Insertion Technique
        //
        // We repeat (right-left) times.
        //
        // Example:
        //
        // 1 -> 2 -> 3 -> 4 -> 5
        //      ^
        //     curr
        //
        // Move node after curr to the front every iteration.
        // -------------------------------------------------------
        for (int i = 0; i < right - left; i++) {

            // temp is the node immediately after curr.
            //
            // 1 -> 2 -> 3 -> 4 -> 5
            //      ^    ^
            //     curr temp
            //
            ListNode* temp = curr->next;

            // Remove temp from its current position.
            //
            // Before:
            // 2 -> 3 -> 4
            //
            // After:
            // 2 ------> 4
            //
            curr->next = temp->next;

            // Insert temp immediately after prev.
            //
            // Before:
            // prev -> 2
            //
            // After:
            // prev -> 3 -> 2
            //
            temp->next = prev->next;

            // Finish insertion.
            //
            // Before:
            // prev -> 2
            //
            // After:
            // prev -> 3 -> 2
            //
            prev->next = temp;
        }

        // dummy.next always points to the actual head.
        return dummy.next;
    }
};