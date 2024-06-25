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
    TreeNode* bstToGst(TreeNode* root) {
        int tot = 0;
        function<void(TreeNode*)> f = [&] (TreeNode* u) {
            if (!u) return;
            tot += u->val;
            f(u->left);
            f(u->right);
        };
        f(root);
        
        int pre = 0;        
        function<void(TreeNode*)> g = [&] (TreeNode* u) {
            if (!u) return;
            g(u->left);
            pre += u->val;
            u->val += tot - pre;
            g(u->right);
        };
        g(root);
        
        return root;
    }
};