/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if((!root )||(!(root->left))) {
            return root;
        }
        TreeNode* cur = root->left;
        TreeNode* pre = root;
        TreeNode* newRoot = upsideDownBinaryTree(cur);
        cur->left = pre->right;
        cur->right = pre;
        pre->left = NULL;
        pre->right = NULL;
        return newRoot;
    }
};
