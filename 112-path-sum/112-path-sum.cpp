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
  bool ans = false;
  int t;
  void f(TreeNode *node, int cum) {
    if (!node) return;
    cum += node->val;
    if (!node->left && !node->right) ans |= cum==t;
    f(node->left, cum);
    f(node->right, cum);
  }
  bool hasPathSum(TreeNode* root, int targetSum) {
    t = targetSum;
    f(root,0);
    return ans;
  }
}; 