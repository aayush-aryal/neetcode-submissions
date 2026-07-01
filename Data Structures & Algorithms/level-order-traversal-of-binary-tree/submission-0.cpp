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

    vector<vector<int>> levelOrder(TreeNode* root) {

        if (root==nullptr){
            return {};
        }

        std::queue<std::pair<TreeNode*,int>> q;
        q.push({root,0});
        int prevLevel=0;
        vector<vector<int>> final;
        vector<int> curr;
        while (!q.empty()){
            auto elem = q.front();
            q.pop();

            TreeNode* node = elem.first;
            int level = elem.second;

            if (level!=prevLevel){
                final.push_back(curr);
                curr.clear();
                prevLevel=level;
            }

            curr.push_back(node->val);

            if (node->left!=nullptr){
                q.push({node->left,level+1});
            }
            if (node->right!=nullptr){
                q.push({node->right,level+1});
            }
        }
        final.push_back(curr);
        return final;
    
        
    }
};
