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
    TreeNode* f(vector<int>& a, int l, int r) {
      if (l>r) return nullptr;
      int mid = (l+r)/2;
      TreeNode* ret = new TreeNode(a[mid]);
      ret->left = f(a,l,mid-1);
      ret->right = f(a,mid+1,r);
      return ret;
    }
   
    TreeNode* sortedArrayToBST(vector<int>& a) {
        int n = a.size();
        return f(a,0,n-1);
    }
};