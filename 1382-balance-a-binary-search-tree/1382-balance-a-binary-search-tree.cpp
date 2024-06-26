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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> a;
        function<void(TreeNode*)> f = [&] (TreeNode* u) {
            if (!u) return;
            f(u->left);
            a.push_back(u->val);
            f(u->right);
        };
        f(root);
        
        int n = a.size();
        function<TreeNode*(int,int)> g =[&] (int l, int r) {
            if (l==r) return new TreeNode(a[l]);
            
            int m = (l+r)/2;
            TreeNode* ret = new TreeNode(a[m]);
            if (l < m) ret->left = g(l,m-1);
            if (r > m) ret->right = g(m+1,r);
            return ret;
        };
        return g(0,n-1);
    }
};