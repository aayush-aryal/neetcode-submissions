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
    ListNode* reverseList(ListNode* head) {

        // to reverse a linked list
        // head->1->2->3->tail
    //before curr after 
        // start from head heads next is nexts prev 
        // before->curr-> after
        ListNode* curr=head;
        ListNode* before=nullptr;
        while (curr!=nullptr){
            ListNode* after= curr->next; 
            curr->next=before;
            before=curr;
            curr=after;
        } 
        return before;  
    }
};
