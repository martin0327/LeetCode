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
  int x,y;
  
  void f(TreeNode *node, int d) {
    if (!node) return;
    if (d == y-1) {
      TreeNode *l = node->left;
      TreeNode *r = node->right;
      node->left = new TreeNode(x);
      node->left->left = l;
      node->right = new TreeNode(x);
      node->right->right = r;
      return;
    }
    f(node->left, d+1);
    f(node->right, d+1);
  }
  TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if (depth==1) {
      TreeNode *rt = new TreeNode(val);
      rt->left = root;
      return rt;
    }
    x = val;
    y = depth;
    f(root,1);
    return root;
  }
}; 