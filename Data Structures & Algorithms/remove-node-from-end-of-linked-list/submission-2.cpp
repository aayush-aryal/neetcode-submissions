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
        // why is this even a medium
        ListNode* curr=head;
        ListNode* prev=nullptr;
        size_t total=0;
        
        // maybe two iterations total-n = index to remove?
        while (curr!=nullptr){
            total+=1;
            curr=curr->next;
        }
        int i=0;
        int index_to_remove=total-n;
        curr=head;
        while (i!=index_to_remove){
            prev=curr;
            curr=curr->next;
            i++;
        }
        
        if( prev==nullptr){
            head=head->next;
        } else{
            prev->next=curr->next;
        }
        return head;
    }

};
