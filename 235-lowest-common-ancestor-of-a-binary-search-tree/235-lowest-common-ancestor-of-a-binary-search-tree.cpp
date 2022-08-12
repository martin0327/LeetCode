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
    TreeNode* res = nullptr;
    TreeNode *pp, *qq;
    int f(TreeNode* node) {
        if (!node) return false;
        int ret = 0;
        if (node==pp || node==qq) ret++;
        ret += f(node->left);
        ret += f(node->right);
        if (ret==2 && res == nullptr) res = node;
        return ret;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pp = p;
        qq = q;
        f(root);
        return res;
    }
};