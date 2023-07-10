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
    int ans = 1e9;
    int minDepth(TreeNode* root) {
        function<void(TreeNode*,int)> f = [&](TreeNode* node, int d) {
            if (!node) return;
            if (!node->left && !node->right) {
                ans = min(ans, d);
                return;
            }
            f(node->left, d+1);
            f(node->right, d+1);
        };
        if (!root) return 0;
        f(root,1);
        return ans;
    }
};