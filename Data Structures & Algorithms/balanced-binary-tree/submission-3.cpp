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
    bool isBalanced(TreeNode* root) {
        int ans=dfs(root);
        return ans!=-1?true:false;   
    }


    int dfs(TreeNode* root){
        if (root==nullptr){
            return 0;
        }
        int left= dfs(root->left);
        int right= dfs(root->right); 

        if (std::abs(left-right)<=1 && left!=-1 && right!=-1){
            return 1+std::max(left,right);
        }
        return -1;
    }
};
