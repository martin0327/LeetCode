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
    int maxLevelSum(TreeNode* root) {
        map<int,int> mp;
        function<void(TreeNode*, int)> f = [&](TreeNode* u, int d) {
            if (!u) return;
            mp[d] += u->val;
            f(u->left, d+1);
            f(u->right, d+1);
        };
        f(root, 1);
        int ans = -1, mx = -2e9;
        for (auto [k,v] : mp) {
            if (v > mx) {
                mx = v;
                ans = k;
            }
        }
        return ans;
    }
};