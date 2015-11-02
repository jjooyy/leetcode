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
    int longestConsecutiveHelper(TreeNode* root, int val, int len, int lenmax) {
        if(!root) {
            return lenmax;
        }
        if(root->val == val) {
            len++;
            val++;
            if(len>lenmax) {
                lenmax = len;
            }
        }
        else {
            len = 1;
            val = root->val + 1;
        }
        return max(longestConsecutiveHelper(root->left, val, len, lenmax), 
                    longestConsecutiveHelper(root->right, val, len, lenmax));
        
    }
    int longestConsecutive(TreeNode* root) {
        if(!root)
            return 0;
        else {
            return longestConsecutiveHelper(root, root->val, 0, 0);
        }
    }
};
