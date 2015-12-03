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
    bool isValidBSTHelper(TreeNode* root, TreeNode *min, TreeNode *max) {
        if(!root) {
            return true; 
        }
        else {
            if((min && root->val <= min->val) ||(max && root->val >= max->val)) {
                return false;
            }
            else {
                return isValidBSTHelper(root->left, min, root)&&isValidBSTHelper(root->right, root, max);
            }
        }
    }
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, NULL, NULL);
    }
};