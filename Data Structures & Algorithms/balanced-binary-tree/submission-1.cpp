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
        auto ans=dfs(root);
        return ans.second;
        
        
    }


    std::pair<int, bool> dfs(TreeNode* root){
        if (root==nullptr){
            return {0,true};
        }
        auto left= dfs(root->left);
        auto right= dfs(root->right); 

        if (left.second==true && right.second==true && std::abs(left.first-right.first)<=1){
            return {1+std::max(left.first,right.first), left.second&right.second};
        }
        return {-1,false};
    }
};
