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
  int rangeSumBST(TreeNode* root, int lo, int hi) {
    if (!root) return 0;
    if (root->val < lo) return rangeSumBST(root->right,lo,hi);
    if (root->val > hi) return rangeSumBST(root->left,lo,hi);
    int ret = root->val;
    ret += rangeSumBST(root->left,lo,hi);
    ret += rangeSumBST(root->right,lo,hi);
    return ret;
  }
};    