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
    vector<int> rightSideView(TreeNode* root) {
        // i think same as bfs but right side only 

        std::queue<TreeNode*> q;
        if (root==nullptr){
            return {};
        }
        q.push({root});
        std::vector<int> right;
        while (!q.empty()){
            int size=q.size();
            for (int i=0;i<size;i++){
                auto elem= q.front();
                q.pop();
                // push all elements but when i reaches the end for each push that to final
                if (i==size-1){
                    right.push_back(elem->val);
                }
                if (elem->left!=nullptr) q.push(elem->left);
                if (elem->right!=nullptr) q.push(elem->right);

            }
                
        }
        return right;   
        
    }
};
