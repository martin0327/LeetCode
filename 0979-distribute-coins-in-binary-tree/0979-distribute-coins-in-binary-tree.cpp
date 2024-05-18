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
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> f = [&] (TreeNode* u) {
            if (!u) return 0;
            int ret = u->val;
            ret += f(u->left);
            ret += f(u->right);
            ret--;
            ans += abs(ret);
            return ret;
        };
        f(root);
        return ans;
    }
};