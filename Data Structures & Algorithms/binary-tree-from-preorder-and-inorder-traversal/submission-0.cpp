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
        if (iS>iE|| preStart>preEnd){
            return nullptr;
        }

        TreeNode* root= new TreeNode(preorder[preStart]);
        auto ptr= std::find(inorder.begin()+iS,inorder.begin()+1+iE,root->val);
        // pointer for the index in inorder (left,root, right) index i= position of root
        int index=ptr-inorder.begin();
        int leftSize= index-iS;

        root->left=bt(preorder,inorder,preStart+1,preStart+leftSize,iS, index-1);
        root->right=bt(preorder,inorder,preStart+leftSize+1, preEnd, index+1, iE);

        return root;
    }



};
