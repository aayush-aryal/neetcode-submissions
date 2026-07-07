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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return bt(preorder,inorder,0, preorder.size()-1,0, inorder.size()-1);
    }

    TreeNode* bt(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int iS, int iE){
        // since we will be updating the start and end of both 
        if (preStart>preEnd || iS>iE){
            return nullptr; 
        }
        // we start taking nodes in order of the start in preorder
        TreeNode* root= new TreeNode(preorder[preStart]);
        // find this nodes index in inorder
        auto ptr= std::find(inorder.begin()+iS,inorder.begin()+iE+1,root->val);
        int index= ptr-inorder.begin();
        // how many nodes on its left
        int leftSize= index- iS;
        root->left=bt(preorder,inorder,preStart+1,preStart+leftSize,iS,index-1);
        root->right=bt(preorder,inorder,preStart+leftSize+1,preEnd, index+1,iE);

        return root;

        
    }



};
