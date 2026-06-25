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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //-->

        ListNode* curr1=l1;
        ListNode* curr2= l2;

        ListNode dummy(0);
        ListNode* curr_node= &dummy;

        int added_val=0;
        int curr_carry=0;

        while( curr1 || curr2){
            ListNode* new_node = new ListNode(0);
            int val1= curr1? curr1->val:0;
            int val2= curr2? curr2->val:0;
            int added_val= val1+val2+curr_carry; 
            curr_carry=0;
            int digit= added_val%10;
            int carry= added_val/10;
            curr_carry=carry;
            new_node->val=digit;
            curr_node->next=new_node;
            curr_node= new_node;
            // advance the pointers
            curr1=curr1?curr1->next:nullptr;
            curr2= curr2? curr2->next:nullptr;
        } 
        if (curr_carry!=0){
            ListNode* new_node= new ListNode(curr_carry);
            curr_node->next = new_node;

        }       
        return dummy.next;   
        
    }
};
