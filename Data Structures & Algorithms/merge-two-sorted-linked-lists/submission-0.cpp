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
        ListNode* curr1=list1;
        ListNode* curr2=list2;
        ListNode* head=nullptr;
        if (curr1==nullptr){
            return curr2;
        }
        if (curr2==nullptr){
            return curr1;
        }
        if (curr1->val>=curr2->val){
            head=curr2;
            curr2=curr2->next;
        }else{
            head=curr1;
            curr1=curr1->next;
        }
        ListNode* head_dup= head;
        // after while loop one of two is null

        while (curr1!=nullptr && curr2!=nullptr){
            if (curr1->val>=curr2->val){
                head->next=curr2;
                curr2=curr2->next;
                head=head->next;
            }else{
                head->next=curr1;
                curr1=curr1->next;
                head=head->next;
            }
        }
        if (curr1==nullptr){
            head->next=curr2;
        }else if (curr2==nullptr){
            head->next=curr1;
        }
        

        return head_dup;
        
    }
};
