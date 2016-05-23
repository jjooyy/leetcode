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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        }
        int n = nums.size();
        if (n == 1) {
            return new TreeNode(nums[0]);
        }
        TreeNode *root = new TreeNode(nums[n/2]);
        vector<int> left(&nums[0], &nums[n/2]);
        vector<int> right(&nums[n/2 + 1], &nums[n]);
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};
