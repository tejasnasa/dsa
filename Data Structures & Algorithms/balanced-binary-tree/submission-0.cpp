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
    int dfs(TreeNode* root, bool &res) {
        if (!root) return 0;

        int leftH = dfs(root->left, res);
        int rightH = dfs(root->right, res);

        res = res && abs(leftH - rightH) <= 1;

        return 1 + max(leftH, rightH);
    }

    bool isBalanced(TreeNode* root) {
        bool res = true;

        dfs(root, res);

        return res;
    }
};
