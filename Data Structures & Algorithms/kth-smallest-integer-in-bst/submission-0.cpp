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
    void solve(TreeNode* root, int& cnt, int& res, int k) {
        if(root == nullptr) return;

        solve(root->left, cnt, res, k);
        cnt++;
        if(cnt == k) {
            res = root->val;
            return;
        }
        solve(root->right, cnt, res, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res, cnt = 0;
        solve(root, cnt, res, k);
        return res;
    }
};