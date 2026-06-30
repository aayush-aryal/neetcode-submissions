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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // a tree is a subtree of another if root and all its children are equal
        // at a certain subroot the tree is the same tree
        if (subRoot==nullptr){
            return true;
        }
        if (root==nullptr){
            return false;
        }

        if (sameTree(root,subRoot)){
            return true;
        }

        return isSubtree(root->left, subRoot)|| isSubtree(root->right, subRoot);
        
    }


    bool sameTree(TreeNode* root, TreeNode* subRoot){
        // base case
        if (root==nullptr && subRoot==nullptr){
            return true;
        }
        if ((root==nullptr && subRoot!=nullptr) || (root!=nullptr && subRoot==nullptr)){
            return false;
        }
        if (root->val!=subRoot->val){
            return false;
        }

        return sameTree(root->left,subRoot->left) && sameTree(root->right, subRoot->right);
    }
};
