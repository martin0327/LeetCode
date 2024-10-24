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
    bool flipEquiv(TreeNode* u, TreeNode* v) {
        if (!u && !v) return true;
        if (!u || !v) return false;
        
        bool ret = false;
        ret |= flipEquiv(u->left,v->left) && flipEquiv(u->right,v->right);
        ret |= flipEquiv(u->left,v->right) && flipEquiv(u->right,v->left);
        ret &= u->val == v->val;
        return ret;
    }
};