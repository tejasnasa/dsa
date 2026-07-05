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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((!p && q) || (p && !q)) return false;
        if (!p && !q) return true;
        if (p->val != q->val) return false;

        bool isLeftSame = isSameTree(p->left,q->left);
        bool isRightSame = isSameTree(p->right,q->right);

        return isRightSame && isLeftSame;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        bool same = false;

        bool isLeftSubtree = isSubtree(root->left, subRoot);
        bool isRightSubtree = isSubtree(root->right, subRoot);

        if (root->val == subRoot->val) {
            same = isSameTree(root, subRoot);
        }

        return isLeftSubtree || isRightSubtree || same;
    }
};
