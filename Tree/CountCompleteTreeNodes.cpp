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
    int countNodes(TreeNode* root) {
        if(!root) {
            return 0;
        }
        else {
            TreeNode* leftTree = root;
            TreeNode* rightTree = root;
            int lefth = 0;
            int righth = 0;
            while(leftTree) {
                leftTree = leftTree->left;
                lefth++;
            }
            while(rightTree) {
                rightTree = rightTree->right;
                righth++;
            }
            if(lefth == righth) {
                return (int)pow(2, lefth) - 1;
            }
            else {
                return 1 + countNodes(root->left) + countNodes(root->right);
            }
        }
    }
};
