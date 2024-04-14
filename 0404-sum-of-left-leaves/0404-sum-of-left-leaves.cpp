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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        function<void(TreeNode*,bool)> f = [&] (TreeNode* u, bool left) {
            if (!u) return;
            if (!u->left && !u->right) {
                if (left) ans += u->val;
            }
            f(u->left, true);
            f(u->right, false);
        };
        f(root,0);
        return ans;
    }
};