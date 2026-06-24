class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        //  find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // merge
        ListNode* l1 = head;
        ListNode* l2 = prev;

        while (l2->next) {
            ListNode* t1 = l1->next;
            ListNode* t2 = l2->next;

            l1->next = l2;
            l2->next = t1;

            l1 = t1;
            l2 = t2;
        }
    }
};