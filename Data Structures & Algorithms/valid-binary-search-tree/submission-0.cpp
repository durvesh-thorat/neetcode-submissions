/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    bool validateBST(TreeNode* root, long mn, long mx) {
        if (root == nullptr)
            return true;
        if (root->val >= mx || root->val <= mn)
            return false;
        return validateBST(root->left, mn, root->val) &&
               validateBST(root->right, root->val, mx);
    }

public:
    bool isValidBST(TreeNode* root) {
        return validateBST(root, LONG_MIN, LONG_MAX);
    }
};