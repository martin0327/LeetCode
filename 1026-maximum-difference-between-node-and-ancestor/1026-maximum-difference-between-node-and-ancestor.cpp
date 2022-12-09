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
  vector<int> f(TreeNode *node) {
    if (!node) return {};
    int x = node->val;
    vector<int> ret = {x};
    for (auto y : f(node->left)) {
      ans = max(ans, abs(x-y));
      ret.push_back(y);
    }
    for (auto y : f(node->right)) {
      ans = max(ans, abs(x-y));
      ret.push_back(y);
    }
    return ret;
  }
  int maxAncestorDiff(TreeNode* root) {
    f(root);
    return ans;
  }
};