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
    int diam(TreeNode* root, int &res) {
        if (!root) return 0;

        int hLeft = diam(root->left, res);
        int hRight = diam(root->right, res);

        res = max(res, hLeft + hRight);

        return 1 + max(hLeft, hRight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;

        diam(root, res);

        return res;
    }
};
