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
    int ans = 0;
    int f(TreeNode *node, bool left) {
        if (!node) return 0;
        int l = f(node->left, true);
        int r = f(node->right, false);
        ans = max(ans,max(l,r));
        if (left) return r+1;
        else return l+1;
    }
    int longestZigZag(TreeNode* root) {
        f(root,left);
        f(root,right);
        return ans;
    }
};