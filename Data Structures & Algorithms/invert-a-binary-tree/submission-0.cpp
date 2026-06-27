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
    TreeNode* invertTree(TreeNode* root) {
        // start at the root
        // the left subtree is the right subtree
        // the rgiht subtree is the left subtree
        // go down till you get to the root

        // base case, if only root there return
        // if you reached the leaf ie no left or right node return
        // else 
        
        // termination case
        invertTree_(root);
        return root;
    }

    void invertTree_(TreeNode* root){
        if (root==nullptr){
            return;
        }
            TreeNode* temp= root->left;
            root->left=root->right;
            root->right=temp;
            // recursive case
            invertTree_(root->left);
            invertTree_(root->right);  
        }
};
