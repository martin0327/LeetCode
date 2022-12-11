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
    int ans = -1e9;
    int f(TreeNode *node) {
        if (!node) return 0;
        int x = node->val;
        int y = f(node->left);
        int z = f(node->right);
        int ret = max({x,x+y,x+z});
        ans = max({ans,ret,x+y+z});
        return ret;        
    }
    int maxPathSum(TreeNode* root) {
        f(root);
        return ans;
    }
}; 