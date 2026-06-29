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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q);
        
    }

    bool dfs(TreeNode*p, TreeNode* q){
        // base cases if p and q are equal and not equal in value
        if (p==nullptr && q==nullptr){
            return true;
        }
        if ((p!=nullptr && q==nullptr)|| (p==nullptr && q!=nullptr)){
            return false;
        }
        if (p->val!=q->val){
            return false;
        }
        // the parent node needs to know if its children are the same
        bool left=dfs(p->left,q->left);
        bool right=dfs(p->right,q->right);
        return left&& right;
    }
};
