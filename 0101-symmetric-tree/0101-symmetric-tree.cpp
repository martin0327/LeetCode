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
  map<int,vector<int>> a,b;
  void f(TreeNode* v, int d, map<int,vector<int>> &mp) {
    if (!v) {
      mp[d].push_back(101);
      return;
    }
    mp[d].push_back(v->val);
    f(v->left, d+1, mp);
    f(v->right,d+1, mp);
  }
  void g(TreeNode* v, int d, map<int,vector<int>> &mp) {
    if (!v) {
      mp[d].push_back(101);
      return;
    }
    mp[d].push_back(v->val);
    g(v->right,d+1, mp);
    g(v->left, d+1, mp);
  }
  bool isSymmetric(TreeNode* root) {
    f(root->left,0,a);
    g(root->right,0,b);
    return a==b;
  }
};