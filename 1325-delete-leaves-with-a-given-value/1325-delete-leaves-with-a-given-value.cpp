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
    TreeNode* removeLeafNodes(TreeNode* root, int tg) {
        function<bool(TreeNode*)> f = [&] (TreeNode* u) {
            if (!u) return false;
            if (f(u->left)) u->left = nullptr;
            if (f(u->right)) u->right = nullptr;
            return (!u->left && !u->right && u->val == tg);
        };
        return f(root) ? nullptr : root;
    }
};