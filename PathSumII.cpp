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
    void findPath(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& pathSum) {
        if(!root ) {
            return;
        }
        vector<int> pathN = path;
        if(root->val == sum) {
            if((!(root->left))&&(!(root->right))) {
                pathN.push_back(root->val);
                pathSum.push_back(pathN);
            }
            else  {
                pathN.push_back(root->val);
                findPath(root->left, sum-root->val, pathN, pathSum);
                findPath(root->right, sum-root->val, pathN, pathSum);
            }
        }
        else {
            pathN.push_back(root->val);
            findPath(root->left, (sum-root->val), pathN, pathSum);
            findPath(root->right, (sum-root->val), pathN, pathSum);
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> path;
        vector<int> p;
        findPath(root, sum, p, path);
        return path;
    }
};