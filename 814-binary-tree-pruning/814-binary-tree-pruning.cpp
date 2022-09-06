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
  int f(TreeNode* node) {
    if (!node) return 0;
    int l = f(node->left);
    int r = f(node->right);
    if (l==0) node->left = nullptr;
    if (r==0) node->right = nullptr;
    int ret = l + r + node->val;
    return ret;    
  }
  TreeNode* pruneTree(TreeNode* root) {
    if (f(root)==0) root = nullptr;
    return root;
  }
};