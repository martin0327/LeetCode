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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> f = [&] (TreeNode* u) {
            if (!u) return 0;
            int l = f(u->left);
            int r = f(u->right);
            ans = max(ans, 1+l+r);
            return 1 + max(l,r);
        };
        f(root);
        return ans-1;
    }
};