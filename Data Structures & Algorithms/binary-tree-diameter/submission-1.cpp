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
    int depth(TreeNode* root, int& maxD) {
        if(root == NULL) return 0;

        int leftMax = depth(root->left, maxD);
        int rightMax = depth(root->right, maxD);

        maxD = max(maxD, leftMax+rightMax);

        return 1 + max(leftMax, rightMax);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        int diameter = 0;
        depth(root, diameter);
        return diameter;
    }
};
