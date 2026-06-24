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
    bool hasCycle(ListNode* head) {
        // fast pointer and slow pointer 
        ListNode* fast=head;
        ListNode* slow=head;

        // if there is a cycle no pointer will be null

        while (fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            // since fast is going twice as fast as slow
            // they will be equal at one point if there is a cycle
            if (slow==fast){
                return true;
            }

        }
        return false;
        
    }
};
