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
    using ll = long long;
    const int mod = 1e9+7;
    
    vector<int> a;
    int f(TreeNode* node) {
        if (!node) return 0;
        int ret = node->val;
        ret += f(node->left);
        ret += f(node->right);
        a.push_back(ret);
        return ret;
    }
    
    int maxProduct(TreeNode* root) {
        ll x = f(root);        
        ll ret = 0;
        for (auto &y : a) ret = max(ret, y*(x-y));
        return ret % mod;
    }
};  