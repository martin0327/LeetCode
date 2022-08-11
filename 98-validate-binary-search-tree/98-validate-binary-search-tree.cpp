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
    using pii = pair<ll,ll>;
    bool ret = true;
    
    pii f(TreeNode* node) {
        if (!node) return {1e18,-1e18};
        auto [min1,max1] = f(node->left);
        if (max1 >= node->val) ret = false;
        auto [min2,max2] = f(node->right);
        if (min2 <= node->val) ret = false;
        min1 = min(min1, (ll) node->val);
        max2 = max(max2, (ll) node->val);
        return {min1,max2};
    }
    bool isValidBST(TreeNode* root) {
        f(root);
        return ret;
    }
};