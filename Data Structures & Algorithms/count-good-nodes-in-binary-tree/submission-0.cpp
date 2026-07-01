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
    int total=0;
    int goodNodes(TreeNode* root) {
        dfs(root,root->val);
        return total;  
    }

    void dfs(TreeNode* root, int currmax){
        if (root==nullptr){
            return;
        }
        if (root->val>=currmax){
            currmax= root->val;
            total++;
        }
        dfs(root->left,currmax);
        dfs(root->right, currmax);
    }

};
