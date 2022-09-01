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
  
  void f(TreeNode* node, int lmax) {
    if (!node) return;
    if (node->val >= lmax) ans++;
    lmax = max(lmax, node->val);
    f(node->left,lmax);
    f(node->right,lmax);
  }
  int goodNodes(TreeNode* root) {
    f(root, -1e9);
    return ans;
  }
};