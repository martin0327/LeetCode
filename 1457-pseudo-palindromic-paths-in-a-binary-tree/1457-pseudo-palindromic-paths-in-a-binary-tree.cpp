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
    int ret = 0;
    void f(TreeNode* node, int mask) {
        mask ^= 1<<(node->val);
        if (node->left) f(node->left, mask);
        if (node->right) f(node->right, mask);
        if (!(node->left || node->right)) {
            if (mask==0 || (mask&(mask-1))==0) ret++;
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        f(root, 0);
        return ret;
    }
};