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
    
    bool found = false;
    TreeNode *ans, *p, *q;
    
    bool f(TreeNode* node) {
        if (!node) return false;
        int ret = 0;
        if (node==p || node==q) ret++;
        ret += f(node->left);
        ret += f(node->right);
        if (!found && ret == 2) {
            found = true;
            ans = node;
        } 
        return ret;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* pp, TreeNode* qq) {
        p = pp;
        q = qq;
        f(root);
        return ans;
    }
};