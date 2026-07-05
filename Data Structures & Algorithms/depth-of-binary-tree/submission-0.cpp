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
    void inorder(TreeNode* root, int &ct, int &res) {
        if (!root) return;
        ct++;
        res = max(ct, res);

        inorder(root->left, ct, res);
        inorder(root->right, ct, res);

        ct--;
    }

    int maxDepth(TreeNode* root) {
        int res = 0;
        int ct = 0;

        inorder(root, ct, res);

        return res;
    }
};
