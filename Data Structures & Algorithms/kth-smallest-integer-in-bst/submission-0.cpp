/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    std::vector<int> inorder_nodes;
    int kthSmallest(TreeNode* root, int k) {
        // main thing with this problem is to find the kth smallest somehow and then go up
        // the smallest node is the leftmost not null node 
        // since we cant go up the tree due to pointers

        // inorder traversal    
        if (root==nullptr){
            return {};
        }
        inorder(root);
        return inorder_nodes[k-1];
    }

    void inorder(TreeNode* root){
        if (root==nullptr){
            return;
        }
        inorder(root->left);
        inorder_nodes.push_back(root->val);
        inorder(root->right);
    }
};
