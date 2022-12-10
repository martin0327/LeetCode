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
    set<int> s = {0, mod};
    int f(TreeNode* node) {
        if (!node) return 0;
        int ret = node->val;
        ret += f(node->left);
        ret += f(node->right);
        s.insert(ret);
        return ret;
    }
    int maxProduct(TreeNode* root) {
        int x = f(root);
        auto it = s.lower_bound(x/2);
        ll y = *it, z = *prev(it);
        if (abs(y-x/2) <= abs(z-x/2)) z = y;
        ll ret = z * (x-z);
        return ret % mod;
    }
}; 