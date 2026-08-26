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
    unordered_map<TreeNode*, int> cache;

    int robb(TreeNode* root) {
        if (!root) return 0;

        if (cache.find(root) != cache.end()) {
            return cache[root];
        }

        int res = root->val;

        if (root->left) {
            res += robb(root->left->left) + robb(root->left->right);
        }

        if (root->right) {
            res += robb(root->right->left) + robb(root->right->right);
        }

        return cache[root] = max(res, robb(root->left) + robb(root->right));
    }

    int rob(TreeNode* root) {
        cache[nullptr] = 0;
        
        return robb(root);
    }
};