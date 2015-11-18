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
    int findkthSmallest(TreeNode* root, int &count) {
        int ret;
        if(root->left) {
            ret = findkthSmallest(root->left, count);
            if(ret)
                return ret;
        }
        count--;
        if(count == 0) {
            return root->val;
        }
        if(root->right) {
            ret = findkthSmallest(root->right, count);
            if(ret)
                return ret;
        }
        return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) {
            return 0;
        }
        int count = k;
        return findkthSmallest(root, count);
    }
};
