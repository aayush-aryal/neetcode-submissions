/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        std::unordered_map<Node*,Node*>links;
        // loop throguh each node for first pass store original:copy
        Node* curr=head;
        while (curr){
            links[curr]=new Node(curr->val);
            curr=curr->next;
        }
        // second pass go throguh the list and link
        curr=head;
        while (curr!=nullptr){
            Node* copy_node= links[curr];
            copy_node->next=curr->next?links[curr->next]:nullptr;
            copy_node->random=curr->random?links[curr->random]:nullptr;
            curr=curr->next;
        }
        return links[head];    
    }
};
