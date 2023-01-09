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
  vector<int> ret;
  void f(TreeNode* v) {
    if (!v) return;
    ret.push_back(v->val);
    f(v->left);
    f(v->right);
  }
  vector<int> preorderTraversal(TreeNode* root) {
    f(root);
    return ret;
  }
};