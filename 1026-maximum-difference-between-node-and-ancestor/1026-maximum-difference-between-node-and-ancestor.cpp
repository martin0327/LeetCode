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
  
  void f(TreeNode *node, int cmin, int cmax) {
    if (!node) return;
    cmin = min(cmin, node->val);
    cmax = max(cmax, node->val);
    ans = max(ans, cmax-cmin);
    f(node->left, cmin, cmax);
    f(node->right, cmin, cmax);
  }

  int maxAncestorDiff(TreeNode* root) {
    f(root, 1e5, 0);
    return ans;
  }    
};   